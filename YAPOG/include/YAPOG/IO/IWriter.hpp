#ifndef YAPOG_IWRITER_HPP
# define YAPOG_IWRITER_HPP

# include "YAPOG/Export.hpp"
# include "YAPOG/Misc/String.hpp"

namespace yap
{
  struct YAPOG_LIB IWriter
  {
      virtual ~IWriter () {}

      virtual void Write (const String& value) = 0;
      virtual void Write (const String& name, const String& value) = 0;

      virtual void Write (const int& value) = 0;
      virtual void Write (const String& name, const int& value) = 0;

      virtual void Write (const unsigned int& value) = 0;
      virtual void Write (const String& name, const unsigned int& value) = 0;

      virtual void Write (const float& value) = 0;
      virtual void Write (const String& name, const float& value) = 0;

      virtual void Write (const double& value) = 0;
      virtual void Write (const String& name, const double& value) = 0;

      virtual void Write (const long double& value) = 0;
      virtual void Write (const String& name, const long double& value) = 0;

      virtual void Write (const char& value) = 0;
      virtual void Write (const String& name, const char& value) = 0;

      virtual void Write (const unsigned char& value) = 0;
      virtual void Write (const String& name, const unsigned char& value) = 0;

      virtual void Write (const bool& value) = 0;
      virtual void Write (const String& name, const bool& value) = 0;

      virtual void Write (const long int& value) = 0;
      virtual void Write (const String& name, const long int& value) = 0;

      virtual void Write (const unsigned long int& value) = 0;
      virtual void Write (const String& name,
                          const unsigned long int& value) = 0;

      virtual void Write (const short int& value) = 0;
      virtual void Write (const String& name, const short int& value) = 0;

      virtual void Write (const unsigned short int& value) = 0;
      virtual void Write (const String& name, unsigned short int& value) = 0;
  };
} /// namespace yap

#endif /// !YAPOG_IWRITER_HPP
