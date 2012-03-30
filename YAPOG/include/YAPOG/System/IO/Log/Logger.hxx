#ifndef YAPOG_LOGGER_HXX
# define YAPOG_LOGGER_HXX

namespace yap
{
  template <typename T>
  inline Logger& Logger::Log (const T& value)
  {
    if (!isActive_)
      return *this;

    WriteValue (value);

    return *this;
  }

  template <typename T>
  inline Logger& Logger::LogLine (const T& value)
  {
    if (!isActive_)
      return *this;

    WriteValue (value);
    *oStream_ << std::endl;

    return *this;
  }

  template <typename T>
  inline void Logger::WriteValue (const T& value)
  {
    if (!isActive_)
      return;

    *oStream_ << value;
  }
} // namespace yap

#endif // YAPOG_LOGGER_HXX
