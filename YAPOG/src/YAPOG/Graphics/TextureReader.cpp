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
    // <Texture id="{id}>

    if (!visitable.TryChangeRoot (xmlRootNodeName_))
      YAPOG_THROW("Failed to read `" + xmlRootNodeName_ + "' node.");

    texture_.SetID (
      visitable.ReadID (
        XmlHelper::GetAttrNodeName (DEFAULT_XML_ID_NODE_NAME)));

    // <name>{name}</name>

    texture_.LoadFromFile (visitable.ReadString (DEFAULT_XML_NAME_NODE_NAME));

    if (!visitable.NodeExists (DEFAULT_XML_RECT_NODE_NAME))
    {
      visitable.UpChangeRoot ();

      return;
    }

    // <rect>{rect}</rect>

    sf::IntRect rect;
    RectReader<int> rectReader (rect, DEFAULT_XML_RECT_NODE_NAME);
    visitable.Accept (rectReader);
    texture_.SetRect (rect);

    visitable.UpChangeRoot ();

    // </Texture>
  }
} // namespace yap
