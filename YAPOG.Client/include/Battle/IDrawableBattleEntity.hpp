#ifndef YAPOG_CLIENT_IDRAWABLEBATTLEENTITYE_HPP
# define YAPOG_CLIENT_IDRAWABLEBATTLEENTITYE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/Game/Battle/IBattleEntity.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"

namespace yap
{
  struct ISprite;
}

namespace ycl
{
  struct IDrawableBattleEntity 
    : public yap::IDrawable
    , public virtual yap::IBattleEntity
  {
    virtual ~IDrawableBattleEntity () {}

    virtual const yap::ISprite& GetBattleSprite () const = 0;
    virtual yap::ISprite& GetBattleSprite () = 0;
    virtual const yap::ISprite& GetIcon () const = 0;
    virtual const yap::ISprite& GetGenderIcon () const = 0;
    virtual const yap::ISprite& GetBattleBack () const = 0;
    virtual const yap::ISprite& GetBattleFront () const = 0;
    virtual const yap::ISprite& GetType1Icon () const = 0;
    virtual const yap::ISprite& GetType2Icon () const = 0;
    virtual void SetPosition (const yap::Vector2& value) = 0;
    virtual void PlayCry () const = 0;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_IDRAWABLEBATTLEENTITYE_HPP
