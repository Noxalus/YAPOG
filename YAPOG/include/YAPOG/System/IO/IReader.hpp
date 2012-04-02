#ifndef YAPOG_IREADER_HPP
# define YAPOG_IREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  struct IReaderVisitor;
  struct IReaderConstVisitor;

  struct YAPOG_LIB IReader
  {
      virtual ~IReader () {}

      virtual void Accept (IReaderVisitor& visitor) = 0;
      virtual void Accept (IReaderConstVisitor& visitor) const = 0;

      virtual String ReadString () = 0;
      virtual String ReadString (const String& name) = 0;

      virtual bool ReadBool () = 0;
      virtual bool ReadBool (const String& name) = 0;

      virtual char ReadChar () = 0;
      virtual char ReadChar (const String& name) = 0;

      virtual uchar ReadUChar () = 0;
      virtual uchar ReadUChar (const String& name) = 0;

      virtual Int16 ReadInt16 () = 0;
      virtual Int16 ReadInt16 (const String& name) = 0;

      virtual UInt16 ReadUInt16 () = 0;
      virtual UInt16 ReadUInt16 (const String& name) = 0;

      virtual int ReadInt () = 0;
      virtual int ReadInt (const String& name) = 0;

      virtual uint ReadUInt () = 0;
      virtual uint ReadUInt (const String& name) = 0;

      virtual Int64 ReadInt64 () = 0;
      virtual Int64 ReadInt64 (const String& name) = 0;

      virtual UInt64 ReadUInt64 () = 0;
      virtual UInt64 ReadUInt64 (const String& name) = 0;

      virtual float ReadFloat () = 0;
      virtual float ReadFloat (const String& name) = 0;

      virtual double ReadDouble () = 0;
      virtual double ReadDouble (const String& name) = 0;

      virtual Vector2 ReadVector2 () = 0;
      virtual Vector2 ReadVector2 (const String& name) = 0;
  };
} // namespace yap

#endif // YAPOG_IREADER_HPP
