#include "YAPOG/System/IO/Log/Logger.hpp"
#include "YAPOG/System/Error/InvalidMethodCallException.hpp"

namespace yap
{
  Logger::Logger (OStream& oStream)
    : oStream_ (&oStream)
    , isActive_ (true)
    , modes_ ()
  {
  }

  Logger::~Logger ()
  {
    for (const auto& it : modes_)
      delete it;
  }

  void Logger::Activate (bool isActive)
  {
    isActive_ = isActive;
  }

  void Logger::AddMode (LoggerMode* mode)
  {
    modes_.Add (mode);
  }

  void Logger::RemoveMode (LoggerMode* mode)
  {
    modes_.Remove (mode);
  }

  void Logger::Write (const String& value)
  {
    Log (value);
  }

  void Logger::Write (const String& name, const String& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const String&)");
  }

  void Logger::Write (const int& value)
  {
    Log (value);
  }

  void Logger::Write (const String& name, const int& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const int&)");
  }

  void Logger::Write (const unsigned int& value)
  {
    Log (value);
  }

  void Logger::Write (const String& name, const unsigned int& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const unsigned int&)");
  }

  void Logger::Write (const float& value)
  {
    Log (value);
  }

  void Logger::Write (const String& name, const float& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const float&)");
  }

  void Logger::Write (const double& value)
  {
    Log (value);
  }

  void Logger::Write (const String& name, const double& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const double&)");
  }

  void Logger::Write (const long double& value)
  {
    Log (value);
  }

  void Logger::Write (const String& name, const long double& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const long double&)");
  }

  void Logger::Write (const char& value)
  {
    Log (value);
  }

  void Logger::Write (const String& name, const char& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const char&)");
  }

  void Logger::Write (const unsigned char& value)
  {
    Log (value);
  }

  void Logger::Write (const String& name, const unsigned char& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const unsigned char&)");
  }

  void Logger::Write (const bool& value)
  {
    Log (value);
  }

  void Logger::Write (const String& name, const bool& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const bool&)");
  }

  void Logger::Write (const long int& value)
  {
    Log (value);
  }

  void Logger::Write (const String& name, const long int& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const long int&)");
  }

  void Logger::Write (const unsigned long int& value)
  {
    Log (value);
  }

  void Logger::Write (
    const String& name,
    const unsigned long int& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const unsigned long int&)");
  }

  void Logger::Write (const short int& value)
  {
    Log (value);
  }

  void Logger::Write (const String& name, const short int& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const short int&)");
  }

  void Logger::Write (const unsigned short int& value)
  {
    Log (value);
  }

  void Logger::Write (const String& name, const unsigned short int& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const unsigned short int&)");
  }
} // namespace yap
