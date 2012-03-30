#ifndef YAPOG_XMLREADER_HPP
# define YAPOG_XMLREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/IOStream.hpp"
# include "YAPOG/System/IO/IReader.hpp"
# include "YAPOG/System/IO/Xml/XmlTree.hpp"

namespace yap
{
  class YAPOG_LIB XmlReader : public IReader
  {
    public:

      XmlReader (IStream& iStream, const String& rootName);
      virtual ~XmlReader ();

      void ChangeRoot (const String& rootName);

      /// @name IReader members.
      /// @{
      virtual String ReadString ();
      virtual String ReadString (const String& name);

      virtual int ReadInt ();
      virtual int ReadInt (const String& name);

      virtual unsigned int ReadUnsignedInt ();
      virtual unsigned int ReadUnsignedInt (const String& name);

      virtual float ReadFloat ();
      virtual float ReadFloat (const String& name);

      virtual double ReadDouble ();
      virtual double ReadDouble (const String& name);

      virtual long double ReadLongDouble ();
      virtual long double ReadLongDouble (const String& name);

      virtual char ReadChar ();
      virtual char ReadChar (const String& name);

      virtual unsigned char ReadUnsignedChar ();
      virtual unsigned char ReadUnsignedChar (const String& name);

      virtual bool ReadBool ();
      virtual bool ReadBool (const String& name);

      virtual long int ReadLongInt ();
      virtual long int ReadLongInt (const String& name);

      virtual unsigned long int ReadUnsignedLongInt ();
      virtual unsigned long int ReadUnsignedLongInt (const String& name);

      virtual short int ReadShortInt ();
      virtual short int ReadShortInt (const String& name);

      virtual unsigned short int ReadUnsignedShortInt ();
      virtual unsigned short int ReadUnsignedShortInt (const String& name);
      /// @}

    private:

      XmlTree data_;
  };
} // namespace yap

#endif // YAPOG_XMLREADER_HPP
