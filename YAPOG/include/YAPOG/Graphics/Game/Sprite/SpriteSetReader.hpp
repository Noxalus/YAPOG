#ifndef YAPOG_SPRITESETREADER_HPP
# define YAPOG_SPRITESETREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Game/Sprite/BaseSpriteReader.hpp"

namespace yap
{
  template <typename K>
  class SpriteSet;

  template <typename K>
  class SpriteSetReader : public BaseSpriteReader
  {
      DISALLOW_COPY(SpriteSetReader);

    public:

      SpriteSetReader (SpriteSet<K>& spriteSet, const String& xmlRootNodeName);
      virtual ~SpriteSetReader ();

      virtual void Visit (XmlReader& visitable);

    private:

      SpriteSet<K>& spriteSet_;
  };
} // namespace yap

# include "YAPOG/Graphics/Game/Sprite/SpriteSetReader.hxx"

#endif // YAPOG_SPRITESETREADER_HPP
