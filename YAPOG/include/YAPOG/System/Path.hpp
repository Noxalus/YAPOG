#ifndef YAPOG_PATH_HPP
# define YAPOG_PATH_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  /// @brief Hanles string paths.
  class YAPOG_LIB Path
  {
    public:

      /// @brief Initializes this Path with @a value.
      /// @param value Value this Path contains.
      explicit Path (const String& value);

      /// @brief Initializes this Path from @a copy.
      /// @param copy Path from which to initialize this Path.
      Path (const Path& copy);
      /// @brief Initializes this Path from @a copy.
      /// @param copy Path from which to initialize this Path.
      Path& operator= (const Path& copy);

      /// @brief Compares the inferiority of this Path by @a right.
      /// For associative key containers handling.
      /// @param right Path to compare this Path with.
      bool operator< (const Path& right) const;

      /// @brief Appends @a path to this Path.
      /// Adds a separator character ('/' by default)
      /// if this Path does not end by that character.
      /// @param path Path to append to this Path.
      Path& Concat (const Path& path);
      /// @brief Appends @a value to this Path.
      /// Does not add any separator character.
      /// @param value String to append to this Path.
      Path& Concat (const String& value);

      /// @brief Appends @a right to @a left.
      /// @param left Path from which to append @a right.
      /// @param right Path to append to @a left.
      static Path Concat (const Path& left, const Path& right);
      /// @brief Appends @a right to @a left.
      /// @param left Path from which to append @a right.
      /// @param right String to append to @a left.
      static Path Concat (const Path& left, const String& right);

      /// @brief Gets the underlying String value of this Path.
      /// @return Underlying value of this Path.
      const String& GetValue () const;

    private:

      /// Separator to use in case of the contatenation of Path.
      static const char DEFAULT_SEPARATOR;

      /// Value of this Path.
      String value_;
  };

  /// @brief Appends @a right to @a left.
  /// @param left Path from which to append @a right.
  /// @param right Path to append to @a left.
  Path operator+ (const Path& left, const Path& right);
  /// @brief Appends @a right to @a left.
  /// @param left Path from which to append @a right.
  /// @param right String to append to @a left.
  Path operator+ (const Path& left, const String& right);
} // namespace yap

#endif // YAPOG_PATH_HPP
