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
  struct IDrawableBattleEntity : public yap::IDrawable
  {
    virtual ~IDrawableBattleEntity () {}

    virtual yap::ISprite& GetFrontSprite () = 0;
    virtual yap::ISprite& GetBackSprite () = 0;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_IDRAWABLEBATTLEENTITYE_HPP
