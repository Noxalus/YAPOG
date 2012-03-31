#ifndef YAPOG_LOGGER_HPP
# define YAPOG_LOGGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/IWriter.hpp"
# include "YAPOG/System/IOStream.hpp"
# include "YAPOG/Collection/List.hpp"
# include "YAPOG/System/IO/Log/LoggerMode.hpp"

namespace yap
{
  class YAPOG_LIB Logger : public IWriter
  {
    public:

      DISALLOW_COPY (Logger);

      Logger (OStream& oStream);
      virtual ~Logger ();

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

      template <typename T>
      Logger& Log (const T& value);

      template <typename T>
      Logger& LogLine (const T& value);

      void AddMode (LoggerMode* mode);
      void RemoveMode (LoggerMode* mode);

    protected:

      void Activate (bool isActive);

    private:

      OStream* oStream_;
      bool isActive_;

      collection::List<LoggerMode*> modes_;
  };
} // namespace yap

# include "YAPOG/System/IO/Log/Logger.hxx"

#endif // YAPOG_LOGGER_HPP
