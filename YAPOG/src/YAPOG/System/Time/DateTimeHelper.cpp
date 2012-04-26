#include "YAPOG/System/Time/DateTimeHelper.hpp"

namespace yap
{
  DateTime DateTimeHelper::Now ()
  {
    return DateTime (boost::posix_time::second_clock::local_time ());
  }

} // namespace yap
