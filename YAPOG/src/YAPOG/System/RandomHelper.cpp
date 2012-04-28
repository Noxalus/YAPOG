#include <cstdlib>

#include "YAPOG/System/RandomHelper.hpp"

namespace yap
{
  void RandomHelper::Init (uint seed)
  {
    srand (seed);
  }

  int RandomHelper::GetNext (const int& min, const int& max)
  {
    return GetNext () % (max - min + 1) + min;
  }

  float RandomHelper::GetNext (const float& min, const float& max)
  {
    return (static_cast<float> (GetNext ()) / RAND_MAX) * (max - min) + min;
  }

  double RandomHelper::GetNext (const double& min, const double& max)
  {
    return (static_cast<double> (GetNext ()) / RAND_MAX) * (max - min) + min;
  }

  int RandomHelper::GetNext ()
  {
    return rand ();
  }
} // namespace yap
