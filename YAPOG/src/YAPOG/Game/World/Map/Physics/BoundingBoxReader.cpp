#include "YAPOG/Game/World/Map/Physics/BoundingBoxReader.hpp"
#include "YAPOG/Game/World/Map/Physics/BoundingBox.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"

namespace yap
{
  BoundingBoxReader::BoundingBoxReader (
    BoundingBox& boundingBox,
    const String& xmlRootNodeName)
    : BaseReaderVisitor ()
    , boundingBox_ (boundingBox)
    , xmlRootNodeName_ (xmlRootNodeName)
  {

  }

  BoundingBoxReader::~BoundingBoxReader ()
  {
  }

  void BoundingBoxReader::Visit (XmlReader& visitable)
  {
    BaseReaderVisitor::Visit (visitable);

    auto reader = visitable.ChangeRoot (xmlRootNodeName_);

    FloatRect rect;
    RectReader rectReader (rect, "rect");
    reader->Accept (rectReader);

    boundingBox_.SetPosition (rect.left, rect.top);
    boundingBox_.SetSize (rect.width, rect.height);

    boundingBox_.SetZ (reader->ReadInt ("z"));
    boundingBox_.SetH (reader->ReadInt ("h"));
  }
} // namespace yap
