#ifndef YAPOG_PATH_HPP
# define YAPOG_PATH_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class Path
  {
    public:

      explicit Path (const String& value);

      Path (const Path& copy);
      Path& operator= (const Path& copy);

      bool operator< (const Path& right) const;

      Path& Concat (const Path& path);
      Path& Concat (const String& value);

      static Path Concat (const Path& left, const Path& right);
      static Path Concat (const Path& left, const String& right);

      const String& Value () const;

    private:

      static const char DEFAULT_SEPARATOR;

      String value_;
  };

  Path operator+ (const Path& left, const Path& right);
  Path operator+ (const Path& left, const String& right);
} // namespace yap

#endif // YAPOG_PATH_HPP
