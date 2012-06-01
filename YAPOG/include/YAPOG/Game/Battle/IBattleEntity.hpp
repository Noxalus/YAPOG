#ifndef YAPOG_IBATTLEENTITYE_HPP
# define YAPOG_IBATTLEENTITYE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Game/IUpdateable.hpp"

namespace yap
{
  struct YAPOG_LIB IBattleEntity : public IUpdateable
  {
    virtual ~IBattleEntity () {}

    virtual const String& GetName () const = 0;
  };
} // namespace yap

#endif // YAPOG_IBATTLEENTITYE_HPP