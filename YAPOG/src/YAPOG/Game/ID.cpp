#include "YAPOG/Game/ID.hpp"

namespace yap
{
  const ID::ValueType ID::DEFAULT_VALUE = 0;

  ID::ID ()
    : value_ (DEFAULT_VALUE)
  {
  }

  ID::ID (ValueType value)
    : value_ (value)
  {
  }

  ID::ID (const ID& copy)
    : value_ (copy.value_)
  {
  }

  ID& ID::operator= (const ID& copy)
  {
    if (this == &copy)
      return *this;

    value_ = copy.value_;

    return *this;
  }

  const ID::ValueType& ID::GetValue () const
  {
    return value_;
  }

  void ID::SetValue (ValueType value)
  {
    value_ = value;
  }

  bool ID::operator== (const ID& right) const
  {
    return value_ == right.value_;
  }

  bool ID::operator!= (const ID& right) const
  {
    return !(*this == right);
  }

  bool ID::operator> (const ID& right) const
  {
    return value_ > right.value_;
  }

  bool ID::operator< (const ID& right) const
  {
    return value_ < right.value_;
  }

  bool ID::operator>= (const ID& right) const
  {
    return !(*this < right);
  }

  bool ID::operator<= (const ID& right) const
  {
    return !(*this > right);
  }

} // namespace yap
