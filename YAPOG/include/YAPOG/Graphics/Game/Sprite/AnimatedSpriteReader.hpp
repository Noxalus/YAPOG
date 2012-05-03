#ifndef YAPOG_ANIMATEDSPRITEREADER_HPP
# define YAPOG_ANIMATEDSPRITEREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/Sprite/BaseSpriteReader.hpp"

namespace yap
{
  class AnimatedSprite;

  class AnimatedSpriteReader : public BaseSpriteReader
  {
      DISALLOW_COPY(AnimatedSpriteReader);

    public:

      AnimatedSpriteReader (
        AnimatedSprite& animatedSprite,
        const String& xmlRootNodeName);
      virtual ~AnimatedSpriteReader ();

      virtual void Visit (XmlReader& visitable);

    private:

      AnimatedSprite& animatedSprite_;
  };
} // namespace yap

#endif // YAPOG_ANIMATEDSPRITEREADER_HPP
