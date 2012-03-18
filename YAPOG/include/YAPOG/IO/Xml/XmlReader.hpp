#ifndef YAPOG_XMLREADER_HPP
# define YAPOG_XMLREADER_HPP

# include <boost/property_tree/xml_parser.hpp>
# include <boost/property_tree/ptree.hpp>

# include "YAPOG/Export.hpp"
# include "YAPOG/Misc/String.hpp"
# include "YAPOG/Misc/IOStream.hpp"
# include "YAPOG/IO/IReader.hpp"

namespace yap
{
  class XmlReader : public IReader
  {
    public:

      XmlReader (IStream& iStream, const String& rootName);
      virtual ~XmlReader ();

      void ChangeRoot (const String& rootName);

      /// \name IReader implementation.
      /// \{
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
      /// \}

    private:

      template <typename T>
      const T Get (const String& name) const;

      void CreateRootData (IStream& iStream, const String& rootName);

      boost::property_tree::ptree rootData_;
      boost::property_tree::ptree* data_;
  };
} /// namespace yap

# include "YAPOG/IO/Xml/XmlReader.hxx"

#endif /// !YAPOG_XMLREADER_HPP
