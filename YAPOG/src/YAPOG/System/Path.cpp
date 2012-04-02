#include "YAPOG/System/Path.hpp"

namespace yap
{
  const char Path::DEFAULT_SEPARATOR = '/';

  Path::Path (const String& value)
    : value_ (value)
  {
  }

  Path::Path (const Path& copy)
    : value_ (copy.value_)
  {
  }

  Path& Path::operator= (const Path& copy)
  {
    if (this == &copy)
      return *this;

    value_ = copy.value_;

    return *this;
  }

  bool Path::operator< (const Path& right) const
  {
    return value_ < right.value_;
  }

  Path& Path::Concat (const Path& right)
  {
    String extension = right.value_;

    if (extension.size () <= 0)
      return *this;

    if (value_[value_.size () - 1] != DEFAULT_SEPARATOR)
      value_ += DEFAULT_SEPARATOR;

    value_ += extension;

    return *this;
  }

  Path& Path::Concat (const String& value)
  {
    value_ += value;

    return *this;
  }

  Path Path::Concat (const Path& left, const Path& right)
  {
    if (left.value_.size () <= 0)
      return right;

    Path result = left;
    String extension = right.value_;

    if (extension.size () <= 0)
      return result;

    if (result.value_[result.value_.size () - 1] != DEFAULT_SEPARATOR)
      result.value_ += DEFAULT_SEPARATOR;

    result.value_ += extension;

    return result;
  }

  Path Path::Concat (const Path& left, const String& right)
  {
    Path result = left;

    result.value_ += right;

    return result;
  }

  const String& Path::Value () const
  {
    return value_;
  }

  Path operator+ (const Path& left, const Path& right)
  {
    return Path::Concat (left, right);
  }

  Path operator+ (const Path& left, const String& right)
  {
    return Path::Concat (left, right);
  }
} // namespace yap
