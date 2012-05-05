#ifndef YAPOG_EXPERIENCETYPE_HPP
# define YAPOG_EXPERIENCETYPE_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  enum class YAPOG_LIB ExperienceType
  {
    Slow,
    MediumSlow,
    MediumFast,
    Fast,
    Fluctuating,
    Erratic
  };
} // namespace yap

#endif // YAPOG_EXPERIENCETYPE_HPP
