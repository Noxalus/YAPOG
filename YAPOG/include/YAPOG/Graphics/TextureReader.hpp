#ifndef YAPOG_TEXTUREREADER_HPP
# define YAPOG_TEXTUREREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/IReaderVisitor.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class Texture;

  class TextureReader : public IReaderVisitor
  {
      DISALLOW_COPY(TextureReader);

    public:

      explicit TextureReader (Texture& texture);
      TextureReader (Texture& texture, const String& xmlRootNodeName);
      virtual ~TextureReader ();

      virtual void Visit (XmlReader& visitable);

    private:

      static const String DEFAULT_XML_ROOT_NODE_NAME;
      static const String DEFAULT_XML_ID_NODE_NAME;
      static const String DEFAULT_XML_NAME_NODE_NAME;
      static const String DEFAULT_XML_RECT_NODE_NAME;

      Texture& texture_;

      String xmlRootNodeName_;
  };
} // namespace yap

#endif // YAPOG_TEXTUREREADER_HPP
