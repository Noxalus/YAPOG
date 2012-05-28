#ifndef YAPOG_IBATTLEENTITYE_HPP
# define YAPOG_IBATTLEENTITYE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  struct YAPOG_LIB IBattleEntity
  {
    virtual ~IBattleEntity () {}

    virtual const String& GetName () const = 0;
  };
} // namespace yap

#endif // YAPOG_IBATTLEENTITYE_HPP