#ifndef YAPOG_SPATIAL3INFO_HPP
# define YAPOG_SPATIAL3INFO_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/SpatialInfo.hpp"

namespace yap
{
  class YAPOG_LIB Spatial3Info : public SpatialInfo
  {
    public:

      Spatial3Info ();
      Spatial3Info (
        const Vector2& position,
        const Vector2& size,
        int z,
        int h);

      Spatial3Info (const Spatial3Info& copy);
      Spatial3Info& operator= (const Spatial3Info& copy);

      const int& GetZ () const;
      const int& GetH () const;

      void SetZ (int z);
      void SetH (int h);

    private:

      static const int DEFAULT_Z;
      static const int DEFAULT_H;

      int z_;
      int h_;
  };
} // namespace yap

#endif // YAPOG_SPATIAL3INFO_HPP
