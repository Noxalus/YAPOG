#ifndef YAPOG_TEXTUREREADER_HPP
# define YAPOG_TEXTUREREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/BaseReaderVisitor.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class Texture;

  class YAPOG_LIB TextureReader : public BaseReaderVisitor
  {
      DISALLOW_COPY(TextureReader);

    public:

      TextureReader (Texture& texture, const String& xmlRootNodeName);
      virtual ~TextureReader ();

      virtual void Visit (XmlReader& visitable);

    private:

      static const String DEFAULT_XML_ID_NODE_NAME;
      static const String DEFAULT_XML_NAME_NODE_NAME;
      static const String DEFAULT_XML_RECT_NODE_NAME;

      Texture& texture_;

      String xmlRootNodeName_;
  };
} // namespace yap

#endif // YAPOG_TEXTUREREADER_HPP
