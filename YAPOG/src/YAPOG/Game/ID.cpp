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

  const ID::ValueType& ID::Value () const
  {
    return value_;
  }

  void ID::ChangeValue (ValueType value)
  {
    value_ = value;
  }

  bool ID::operator== (const ID& right)
  {
    return value_ == right.value_;
  }

  bool ID::operator!= (const ID& right)
  {
    return !(*this == right);
  }

  bool ID::operator> (const ID& right)
  {
    return value_ > right.value_;
  }

  bool ID::operator< (const ID& right)
  {
    return value_ < right.value_;
  }

  bool ID::operator>= (const ID& right)
  {
    return !(*this < right);
  }

  bool ID::operator<= (const ID& right)
  {
    return !(*this > right);
  }
} // namespace yap
