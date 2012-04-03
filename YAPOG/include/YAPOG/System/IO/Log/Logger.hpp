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
      DISALLOW_COPY (Logger);

    public:

      explicit Logger (OStream& oStream);
      virtual ~Logger ();

      /// @name IWriter members.
      /// @{
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
      virtual void Write (const String& name, const Vector2& value);
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
