#ifndef YAPOG_ISPATIAL3_HPP
# define YAPOG_ISPATIAL3_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/ISpatial.hpp"

namespace yap
{
  /// @brief Interface representing objects that evolve in 3D space.
  struct ISpatial3 : public ISpatial
  {
      virtual ~ISpatial3 () {}

      /// @brief Gets the highness of this ISpatial3.
      /// @return The highness of this ISpatial3.
      virtual const int& GetZ () const = 0;
      /// @brief Sets the highness of this ISpatial3.
      /// @param z Highness of this ISpatial3.
      virtual void SetZ (int z) = 0;

      /// @brief Gets the height of this ISpatial3.
      /// @return The height of this ISpatial3.
      virtual const int& GetH () const = 0;
      /// @brief Sets the height of this ISpatial3.
      /// @param h Height of this ISpatial3.
      virtual void SetH (int h) = 0;
  };
} // namespace yap

#endif // YAPOG_ISPATIAL3_HPP
