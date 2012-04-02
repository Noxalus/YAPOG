#ifndef YAPOG_XMLWRITER_HPP
# define YAPOG_XMLWRITER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/IWriter.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/IOStream.hpp"
# include "YAPOG/System/IO/Xml/XmlTree.hpp"

namespace yap
{
  class YAPOG_LIB XmlWriter : public IWriter
  {
      DISALLOW_COPY(XmlWriter);

    public:

      XmlWriter (OStream& oStream, const String& rootName);
      virtual ~XmlWriter ();

      void ChangeRoot (const String& rootName);
      void Dump ();

      /// @name IWriter members.
      /// @{
      virtual void Accept (IWriterVisitor& visitor);
      virtual void Accept (IWriterConstVisitor& visitor) const;

      virtual void Write (const String& value);
      virtual void Write (const String& name, const String& value);

      virtual void Write (const bool& value);
      virtual void Write (const String& name, const bool& value);

      virtual void Write (const char& value);
      virtual void Write (const String& name, const char& value);

      virtual void Write (const uchar& value);
      virtual void Write (const String& name, const uchar& value);

      virtual void Write (const Int16& value);
      virtual void Write (const String& name, const Int16& value);

      virtual void Write (const UInt16& value);
      virtual void Write (const String& name, const UInt16& value);

      virtual void Write (const int& value);
      virtual void Write (const String& name, const int& value);

      virtual void Write (const uint& value);
      virtual void Write (const String& name, const uint& value);

      virtual void Write (const Int64& value);
      virtual void Write (const String& name, const Int64& value);

      virtual void Write (const UInt64& value);
      virtual void Write (const String& name, const UInt64& value);

      virtual void Write (const float& value);
      virtual void Write (const String& name, const float& value);

      virtual void Write (const double& value);
      virtual void Write (const String& name, const double& value);

      virtual void Write (const Vector2& value);
      /// @todo Determine representation of Vector2 in XML.
      virtual void Write (const String& name, const Vector2& value);
      /// @}

    private:

      XmlTree data_;
      OStream& oStream_;
  };
} // namespace yap

#endif // YAPOG_XMLWRITER_HPP
