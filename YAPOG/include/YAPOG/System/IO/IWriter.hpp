#ifndef YAPOG_IWRITER_HPP
# define YAPOG_IWRITER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/Game/ID.hpp"

namespace yap
{
  struct IWriterVisitor;
  struct IWriterConstVisitor;

  struct YAPOG_LIB IWriter
  {
      virtual ~IWriter () {}

      virtual void Accept (IWriterVisitor& visitor) = 0;
      virtual void Accept (IWriterConstVisitor& visitor) const = 0;

      virtual void Write (const String& value) = 0;
      virtual void Write (const String& name, const String& value) = 0;

      virtual void Write (const bool& value) = 0;
      virtual void Write (const String& name, const bool& value) = 0;

      virtual void Write (const char& value) = 0;
      virtual void Write (const String& name, const char& value) = 0;

      virtual void Write (const uchar& value) = 0;
      virtual void Write (const String& name, const uchar& value) = 0;

      virtual void Write (const Int16& value) = 0;
      virtual void Write (const String& name, const Int16& value) = 0;

      virtual void Write (const UInt16& value) = 0;
      virtual void Write (const String& name, const UInt16& value) = 0;

      virtual void Write (const int& value) = 0;
      virtual void Write (const String& name, const int& value) = 0;

      virtual void Write (const uint& value) = 0;
      virtual void Write (const String& name, const uint& value) = 0;

      virtual void Write (const Int64& value) = 0;
      virtual void Write (const String& name, const Int64& value) = 0;

      virtual void Write (const UInt64& value) = 0;
      virtual void Write (const String& name, const UInt64& value) = 0;

      virtual void Write (const float& value) = 0;
      virtual void Write (const String& name, const float& value) = 0;

      virtual void Write (const double& value) = 0;
      virtual void Write (const String& name, const double& value) = 0;

      virtual void Write (const Vector2& value) = 0;
      virtual void Write (const String& name, const Vector2& value) = 0;

      virtual void Write (const ID& value) = 0;
      virtual void Write (const String& name, const ID& value) = 0;
  };
} // namespace yap

#endif // YAPOG_IWRITER_HPP
