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
    public:

      XmlWriter (OStream& oStream, const String& rootName);
      virtual ~XmlWriter ();

      void ChangeRoot (const String& rootName);
      void Dump ();

      /// @name IWriter members.
      /// @{
      virtual void Write (const String& value);
      virtual void Write (const String& name, const String& value);

      virtual void Write (const int& value);
      virtual void Write (const String& name, const int& value);

      virtual void Write (const unsigned int& value);
      virtual void Write (const String& name, const unsigned int& value);

      virtual void Write (const float& value);
      virtual void Write (const String& name, const float& value);

      virtual void Write (const double& value);
      virtual void Write (const String& name, const double& value);

      virtual void Write (const long double& value);
      virtual void Write (const String& name, const long double& value);

      virtual void Write (const char& value);
      virtual void Write (const String& name, const char& value);

      virtual void Write (const unsigned char& value);
      virtual void Write (const String& name, const unsigned char& value);

      virtual void Write (const bool& value);
      virtual void Write (const String& name, const bool& value);

      virtual void Write (const long int& value);
      virtual void Write (const String& name, const long int& value);

      virtual void Write (const unsigned long int& value);
      virtual void Write (const String& name,
                          const unsigned long int& value);

      virtual void Write (const short int& value);
      virtual void Write (const String& name, const short int& value);

      virtual void Write (const unsigned short int& value);
      virtual void Write (const String& name, const unsigned short int& value);
      /// @}

    private:

      XmlTree data_;
      OStream& oStream_;
  };
} // namespace yap

#endif // YAPOG_XMLWRITER_HPP
