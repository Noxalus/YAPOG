#ifndef YAPOG_EXCEPTION_HPP
# define YAPOG_EXCEPTION_HPP

# include <exception>

# include "YAPOG/Macros.hpp"

namespace yap
{
  class YAPOG_LIB Exception : public std::exception
  {
  };
} // namespace yap

#endif // YAPOG_EXCEPTION_HPP
