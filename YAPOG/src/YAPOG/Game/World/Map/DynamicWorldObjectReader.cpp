#include "YAPOG/Game/World/Map/DynamicWorldObjectReader.hpp"
#include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"
#include "YAPOG/Game/World/Map/Physics/ForceToVelocityPhysicsCore.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReaderCollection.hpp"
#include "YAPOG/Game/World/Map/Physics/BoundingBox.hpp"
#include "YAPOG/Game/World/Map/Physics/BoundingBoxReader.hpp"

namespace yap
{
  const String DynamicWorldObjectReader::DEFAULT_XML_MAX_VELOCITY_NODE_NAME =
    "maxVelocity";

  DynamicWorldObjectReader::DynamicWorldObjectReader (
    DynamicWorldObject& dynamicWorldObject,
    const String& xmlRootNodeName)
    : WorldObjectReader (dynamicWorldObject, xmlRootNodeName)
    , dynamicWorldObject_ (dynamicWorldObject)
  {
  }

  DynamicWorldObjectReader::~DynamicWorldObjectReader ()
  {
  }

  void DynamicWorldObjectReader::Visit (XmlReader& visitable)
  {
    WorldObjectReader::Visit (visitable);

    auto reader = visitable.ChangeRoot (xmlRootNodeName_);

    if (reader->NodeExists (DEFAULT_XML_MAX_VELOCITY_NODE_NAME))
      dynamicWorldObject_.SetMaxVelocity (
        reader->ReadVector2 (
          DEFAULT_XML_MAX_VELOCITY_NODE_NAME));
    else
      dynamicWorldObject_.SetMaxVelocity (
        DynamicWorldObject::DEFAULT_MAX_VELOCITY);

    PhysicsCore* physicsCore = new ForceToVelocityPhysicsCore ();
    physicsCore->SetVelocityBounds (
      Vector2 (),
      dynamicWorldObject_.GetMaxVelocity ());

    dynamicWorldObject_.SetPhysicsCore (physicsCore);

    if (!reader->NodeExists ("events"))
      return;

    auto boundingBoxesReader = reader->ChangeRoot ("events");

    XmlReaderCollection boundingBoxReaders;
    boundingBoxesReader->ReadNodes ("entry", boundingBoxReaders);
    for (auto& xmlBoundingBoxReader : boundingBoxReaders)
    {
      BoundingBox* boundingBox = new BoundingBox ();
      BoundingBoxReader boundingBoxReader (*boundingBox, "BoundingBox");
      xmlBoundingBoxReader->Accept (boundingBoxReader);

      dynamicWorldObject_.AddTriggerBoundingBox (boundingBox);
    }
  }
} // namespace yap
