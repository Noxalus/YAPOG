#ifndef YAPOG_IGENLOADER_HPP
# define YAPOG_IGENLOADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Factory/ILoader.hpp"

namespace yap
{
  template <typename T>
  struct IGenLoader : public ILoader
  {
      virtual ~IGenLoader () {}
  };
} // namespace yap

#endif // YAPOG_IGENLOADER_HPP
