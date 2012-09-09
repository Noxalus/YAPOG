#ifndef YAPOG_ICOLLISIONCHECKER_HPP
# define YAPOG_ICOLLISIONCHECKER_HPP

# include "YAPOG/Game/World/Map/IWorldObjectConstVisitor.hpp"

namespace yap
{
  struct ICollisionResponse;

  struct ICollisionChecker : public IWorldObjectConstVisitor
  {
      virtual ~ICollisionChecker () { }

      virtual ICollisionResponse& GetResponse () = 0;
  };
} // namespace yap

#endif // YAPOG_ICOLLISIONCHECKER_HPP
