#include "YAPOG/Game/World/Map/WorldObjectReader.hpp"
#include "YAPOG/Game/World/Map/WorldObject.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReaderCollection.hpp"
#include "YAPOG/Game/World/Map/Physics/BoundingBox.hpp"
#include "YAPOG/Game/World/Map/Physics/BoundingBoxReader.hpp"

namespace yap
{
  WorldObjectReader::WorldObjectReader (
    WorldObject& worldObject,
    const String& xmlRootNodeName)
    : xmlRootNodeName_ (xmlRootNodeName)
    , worldObject_ (worldObject)

  {
  }

  WorldObjectReader::~WorldObjectReader ()
  {
  }

  void WorldObjectReader::Visit (XmlReader& visitable)
  {
    BaseReaderVisitor::Visit (visitable);

    auto reader = visitable.ChangeRoot (xmlRootNodeName_);

    auto boundingBoxesReader = reader->ChangeRoot ("boundingBoxes");

    XmlReaderCollection boundingBoxReaders;
    boundingBoxesReader->ReadNodes ("BoundingBox", boundingBoxReaders);
    for (auto& xmlBoundingBoxReader : boundingBoxReaders)
    {
      BoundingBox* boundingBox = new BoundingBox ();
      BoundingBoxReader boundingBoxReader (*boundingBox, "BoundingBox");
      xmlBoundingBoxReader->Accept (boundingBoxReader);

      worldObject_.AddBoundingBox (boundingBox);
    }
  }
} // namespace yap
