#ifndef YAPOG_SPRITEREADER_HPP
# define YAPOG_SPRITEREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/Sprite/BaseSpriteReader.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class Sprite;

  class YAPOG_LIB SpriteReader : public BaseSpriteReader
  {
      DISALLOW_COPY(SpriteReader);

    public:

      SpriteReader (Sprite& sprite, const String& xmlRootNodeName);
      virtual ~SpriteReader ();

      virtual void Visit (XmlReader& visitable);

    private:

      static const String DEFAULT_XML_TEXTURE_NODE_NAME;
      static const String DEFAULT_XML_TEXTURE_ID_NODE_NAME;

      Sprite& sprite_;
  };
} // namespace yap

#endif // YAPOG_SPRITEREADER_HPP
