#include "YAPOG/Game/World/Map/DynamicWorldObjectReader.hpp"
#include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"
#include "YAPOG/Game/World/Map/Physics/PersistentPhysicsCore.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"

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

    dynamicWorldObject_.SetMaxVelocity (
      reader->ReadVector2 (
        DEFAULT_XML_MAX_VELOCITY_NODE_NAME));

    PhysicsCore* physicsCore = new PersistentPhysicsCore ();
    physicsCore->SetVelocityBounds (
      Vector2 (),
      dynamicWorldObject_.GetMaxVelocity ());

    dynamicWorldObject_.SetPhysicsCore (physicsCore);
  }
} // namespace yap
