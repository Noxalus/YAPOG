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

  void Logger::Write (const bool& value)
  {
    Log (value);
  }

  void Logger::Write (const String& name, const bool& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const bool&)");
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

  void Logger::Write (const uchar& value)
  {
    Log (value);
  }

  void Logger::Write (const String& name, const uchar& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const uchar&)");
  }

  void Logger::Write (const Int16& value)
  {
    Log (value);
  }

  void Logger::Write (const String& name, const Int16& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const Int16&)");
  }

  void Logger::Write (const UInt16& value)
  {
    Log (value);
  }

  void Logger::Write (const String& name, const UInt16& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const UInt16&)");
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

  void Logger::Write (const uint& value)
  {
    Log (value);
  }

  void Logger::Write (const String& name, const uint& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const uint&)");
  }

  void Logger::Write (const Int64& value)
  {
    Log (value);
  }

  void Logger::Write (const String& name, const Int64& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const Int64&)");
  }

  void Logger::Write (const UInt64& value)
  {
    Log (value);
  }

  void Logger::Write (const String& name, const UInt64& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const UInt64&)");
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

  void Logger::Write (const Vector2& value)
  {
    Log ("( ").
      Log (value.x).
      Log (", ").
      Log (value.y).
      Log (" )");
  }

  void Logger::Write (const String& name, const Vector2& value)
  {
    throw InvalidMethodCallException (
      "Logger::Write (const String&, const Vector2&)");
  }
} // namespace yap
