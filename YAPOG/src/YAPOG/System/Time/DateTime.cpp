#include "YAPOG/System/Time/DateTime.hpp"

namespace yap
{
  DateTime::DateTime (const InnerTimeType& time)
    : time_ (time)
  {
  }

  DateTime::DateTime (const DateTime& copy)
    : time_ (copy.time_)
  {
  }

  DateTime& DateTime::operator= (const DateTime& copy)
  {
    if (this == &copy)
      return *this;

    time_ = copy.time_;

    return *this;
  }

  String DateTime::ToFullDateString () const
  {
    return boost::posix_time::to_simple_string (time_);
  }
} // namespace yap
