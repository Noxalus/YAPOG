#ifndef YAPOG_RANDOMHELPER_HPP
# define YAPOG_RANDOMHELPER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"

namespace yap
{
  class YAPOG_LIB RandomHelper
  {
      DISALLOW_COPY(RandomHelper);

    public:

      static void Init (uint seed);

      static int GetNext (const int& min, const int& max);
      static float GetNext (const float& min, const float& max);
      static double GetNext (const double& min, const double& max);
      static bool Pourcentage (const float& pourcentage);

    private:

      static int GetNext ();

      RandomHelper ();
      ~RandomHelper ();
  };
} // namespace yap

#endif // YAPOG_RANDOMHELPER_HPP
