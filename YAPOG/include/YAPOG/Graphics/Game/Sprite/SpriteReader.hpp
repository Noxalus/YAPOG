#ifndef YAPOG_SPRITEREADER_HPP
# define YAPOG_SPRITEREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/IReaderVisitor.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class Sprite;

  class YAPOG_LIB SpriteReader : public IReaderVisitor
  {
      DISALLOW_COPY(SpriteReader);

    public:

      explicit SpriteReader (Sprite& sprite);
      SpriteReader (Sprite& sprite, const String& xmlRootNodeName);
      virtual ~SpriteReader ();

      virtual void Visit (XmlReader& visitable);

    private:

      static const String DEFAULT_XML_ROOT_NODE_NAME;
      static const String DEFAULT_XML_TEXTURE_NODE_NAME;
      static const String DEFAULT_XML_TEXTURE_ID_NODE_NAME;

      Sprite& sprite_;

      String xmlRootNodeName_;
  };
} // namespace yap

#endif // YAPOG_SPRITEREADER_HPP
