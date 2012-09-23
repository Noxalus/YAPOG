#ifndef YAPOG_DEFAULTCLONER_HPP
# define YAPOG_DEFAULTCLONER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Factory/ICloner.hpp"

namespace yap
{
  template <typename T>
  class DefaultCloner : public ICloner<T>
  {
      DISALLOW_COPY(DefaultCloner);

    public:

      DefaultCloner ();

      virtual ~DefaultCloner ();

      virtual T* Clone (const T& object) const;
  };
} // namespace yap

# include "YAPOG/Game/Factory/DefaultCloner.hxx"

#endif // YAPOG_DEFAULTCLONER_HPP
