#include "YAPOG/Game/World/Map/DestructibleObjectReader.hpp"
#include "YAPOG/Game/World/Map/DestructibleObject.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/Game/World/Map/Physics/BoundingBox.hpp"
#include "YAPOG/Game/World/Map/Physics/BoundingBoxReader.hpp"

namespace yap
{
  DestructibleObjectReader::DestructibleObjectReader (
    DestructibleObject& destructibleObject,
    const String& xmlRootNodeName)
    : DynamicWorldObjectReader (destructibleObject, xmlRootNodeName)
    , destructibleObject_ (destructibleObject)
  {
  }

  DestructibleObjectReader::~DestructibleObjectReader ()
  {
  }

  void DestructibleObjectReader::Visit (XmlReader& visitable)
  {
    DynamicWorldObjectReader::Visit (visitable);

    auto reader = visitable.ChangeRoot (xmlRootNodeName_);

    auto destructionBoxReader = reader->ChangeRoot ("destructionBox");

    BoundingBox* destructionBox = new BoundingBox ();
    BoundingBoxReader boundingBoxReader (*destructionBox, "BoundingBox");
    destructionBoxReader->Accept (boundingBoxReader);

    destructibleObject_.SetDestructionBox (destructionBox);
  }
} // namespace yap
