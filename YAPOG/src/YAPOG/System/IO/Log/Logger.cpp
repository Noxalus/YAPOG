#include "YAPOG/System/IO/Log/Logger.hpp"
#include "YAPOG/System/Error/InvalidMethodCallException.hpp"

namespace yap
{
  Logger::Logger (OStream& oStream)
    : oStream_ (&oStream)
    , isActive_ (true)
  {
  }

  Logger::~Logger ()
  {
  }

  void Logger::Activate (bool isActive)
  {
    isActive_ = isActive;
  }

  void Logger::Write (const String& value)
  {
    WriteValue (value);
  }

  void Logger::Write (const String& name, const String& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const String&)");
  }

  void Logger::Write (const int& value)
  {
    WriteValue (value);
  }

  void Logger::Write (const String& name, const int& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const int&)");
  }

  void Logger::Write (const unsigned int& value)
  {
    WriteValue (value);
  }

  void Logger::Write (const String& name, const unsigned int& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const unsigned int&)");
  }

  void Logger::Write (const float& value)
  {
    WriteValue (value);
  }

  void Logger::Write (const String& name, const float& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const float&)");
  }

  void Logger::Write (const double& value)
  {
    WriteValue (value);
  }

  void Logger::Write (const String& name, const double& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const double&)");
  }

  void Logger::Write (const long double& value)
  {
    WriteValue (value);
  }

  void Logger::Write (const String& name, const long double& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const long double&)");
  }

  void Logger::Write (const char& value)
  {
    WriteValue (value);
  }

  void Logger::Write (const String& name, const char& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const char&)");
  }

  void Logger::Write (const unsigned char& value)
  {
    WriteValue (value);
  }

  void Logger::Write (const String& name, const unsigned char& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const unsigned char&)");
  }

  void Logger::Write (const bool& value)
  {
    WriteValue (value);
  }

  void Logger::Write (const String& name, const bool& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const bool&)");
  }

  void Logger::Write (const long int& value)
  {
    WriteValue (value);
  }

  void Logger::Write (const String& name, const long int& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const long int&)");
  }

  void Logger::Write (const unsigned long int& value)
  {
    WriteValue (value);
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
    WriteValue (value);
  }

  void Logger::Write (const String& name, const short int& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const short int&)");
  }

  void Logger::Write (const unsigned short int& value)
  {
    WriteValue (value);
  }

  void Logger::Write (const String& name, const unsigned short int& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const unsigned short int&)");
  }
} // namespace yap
