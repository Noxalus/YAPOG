#ifndef YAPOG_ISPATIAL3_HPP
# define YAPOG_ISPATIAL3_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/ISpatial.hpp"

namespace yap
{
  struct ISpatial3 : public ISpatial
  {
      virtual ~ISpatial3 () {}

      virtual const int& GetZ () const = 0;
      virtual void SetZ (int z) = 0;

      virtual const int& GetH () const = 0;
      virtual void SetH (int h) = 0;
  };
} // namespace yap

#endif // YAPOG_ISPATIAL3_HPP
