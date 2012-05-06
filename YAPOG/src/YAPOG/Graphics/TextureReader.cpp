#include "YAPOG/Graphics/TextureReader.hpp"
#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/IO/Xml/XmlHelper.hpp"
#include "YAPOG/Graphics/RectReader.hpp"
#include "YAPOG/System/Error/Exception.hpp"

namespace yap
{
  const String TextureReader::DEFAULT_XML_ROOT_NODE_NAME = "Texture";
  const String TextureReader::DEFAULT_XML_ID_NODE_NAME = "id";
  const String TextureReader::DEFAULT_XML_NAME_NODE_NAME = "name";
  const String TextureReader::DEFAULT_XML_RECT_NODE_NAME = "rect";

  TextureReader::TextureReader (Texture& texture)
    : texture_ (texture)
    , xmlRootNodeName_ (DEFAULT_XML_ROOT_NODE_NAME)
  {
  }

  TextureReader::TextureReader (
    Texture& texture,
    const String& xmlRootNodeName)
    : texture_ (texture)
    , xmlRootNodeName_ (xmlRootNodeName)
  {
  }

  TextureReader::~TextureReader ()
  {
  }

  void TextureReader::Visit (XmlReader& visitable)
  {
    auto reader = visitable.ChangeRoot (xmlRootNodeName_);

    texture_.SetID (
      reader->ReadID (
        XmlHelper::GetAttrNodeName (DEFAULT_XML_ID_NODE_NAME)));

    texture_.LoadFromFile (reader->ReadString (DEFAULT_XML_NAME_NODE_NAME));

    if (!reader->NodeExists (DEFAULT_XML_RECT_NODE_NAME))
      return;

    sf::IntRect rect;
    RectReader<int> rectReader (rect, DEFAULT_XML_RECT_NODE_NAME);
    reader->Accept (rectReader);
    texture_.SetRect (rect);
  }
} // namespace yap
