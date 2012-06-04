#ifndef YAPOG_CLIENT_IDRAWABLEBATTLEENTITYE_HPP
# define YAPOG_CLIENT_IDRAWABLEBATTLEENTITYE_HPP

# include "YAPOG/Macros.hpp"
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

    virtual yap::ISprite& GetBattleSprite () = 0;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_IDRAWABLEBATTLEENTITYE_HPP
