#include "YAPOG/Game/World/Spatial3Info.hpp"

namespace yap
{
  const int Spatial3Info::DEFAULT_Z = 0;
  const int Spatial3Info::DEFAULT_H = 1;

  Spatial3Info::Spatial3Info ()
    : SpatialInfo ()
    , z_ (DEFAULT_Z)
    , h_ (DEFAULT_H)
  {
  }

  Spatial3Info::Spatial3Info (
    const Vector2& position,
    const Vector2& size,
    int z,
    int h)
    : SpatialInfo (position, size)
    , z_ (z)
    , h_ (h)
  {
  }

  Spatial3Info::Spatial3Info (const Spatial3Info& copy)
    : SpatialInfo (copy)
    , z_ (copy.z_)
    , h_ (copy.h_)
  {
  }

  Spatial3Info& Spatial3Info::operator= (const Spatial3Info& copy)
  {
    if (this == &copy)
      return *this;

    SpatialInfo::operator= (copy);

    z_ = copy.z_;
    h_ = copy.h_;

    return *this;
  }

  const int& Spatial3Info::GetZ () const
  {
    return z_;
  }

  const int& Spatial3Info::GetH () const
  {
    return h_;
  }

  void Spatial3Info::SetZ (int z)
  {
    z_ = z;
  }

  void Spatial3Info::SetH (int h)
  {
    h_ = h;
  }
} // namespace yap
