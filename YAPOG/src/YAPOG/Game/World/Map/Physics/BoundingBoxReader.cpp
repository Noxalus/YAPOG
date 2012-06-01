#include "YAPOG/Game/World/Map/Physics/BoundingBoxReader.hpp"
#include "YAPOG/Game/World/Map/Physics/BoundingBox.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/Graphics/RectReader.hpp"

namespace yap
{
  BoundingBoxReader::BoundingBoxReader (
    BoundingBox& boundingBox,
    const String& xmlRootNodeName)
    : BaseReaderVisitor ()
    , xmlRootNodeName_ (xmlRootNodeName)
    , boundingBox_ (boundingBox)
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
    RectReader<float> rectReader (rect, "rect");
    reader->Accept (rectReader);

    boundingBox_.SetPosition (Vector2 (rect.left, rect.top));
    boundingBox_.SetSize (Vector2 (rect.width, rect.height));

    boundingBox_.SetZ (reader->ReadInt ("z"));
    boundingBox_.SetH (reader->ReadInt ("h"));
  }
} // namespace yap
