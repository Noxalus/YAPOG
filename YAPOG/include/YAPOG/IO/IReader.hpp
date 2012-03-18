#ifndef YAPOG_IREADER_HPP
# define YAPOG_IREADER_HPP

# include "YAPOG/Export.hpp"
# include "YAPOG/Misc/String.hpp"

namespace yap
{
  struct YAPOG_LIB IReader
  {
      virtual ~IReader () {}

      virtual String ReadString () = 0;
      virtual String ReadString (const String& name) = 0;

      virtual int ReadInt () = 0;
      virtual int ReadInt (const String& name) = 0;

      virtual unsigned int ReadUnsignedInt () = 0;
      virtual unsigned int ReadUnsignedInt (const String& name) = 0;

      virtual float ReadFloat () = 0;
      virtual float ReadFloat (const String& name) = 0;

      virtual double ReadDouble () = 0;
      virtual double ReadDouble (const String& name) = 0;

      virtual long double ReadLongDouble () = 0;
      virtual long double ReadLongDouble (const String& name) = 0;

      virtual char ReadChar () = 0;
      virtual char ReadChar (const String& name) = 0;

      virtual unsigned char ReadUnsignedChar () = 0;
      virtual unsigned char ReadUnsignedChar (const String& name) = 0;

      virtual bool ReadBool () = 0;
      virtual bool ReadBool (const String& name) = 0;

      virtual long int ReadLongInt () = 0;
      virtual long int ReadLongInt (const String& name) = 0;

      virtual unsigned long int ReadUnsignedLongInt () = 0;
      virtual unsigned long int ReadUnsignedLongInt (const String& name) = 0;

      virtual short int ReadShortInt () = 0;
      virtual short int ReadShortInt (const String& name) = 0;

      virtual unsigned short int ReadUnsignedShortInt () = 0;
      virtual unsigned short int ReadUnsignedShortInt (const String& name) = 0;
  };
} /// namespace yap

#endif /// !YAPOG_IREADER_HPP
