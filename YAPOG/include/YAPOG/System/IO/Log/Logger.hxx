#ifndef YAPOG_LOGGER_HXX
# define YAPOG_LOGGER_HXX

namespace yap
{
  template <typename T>
  inline Logger& Logger::Log (const T& value)
  {
    if (!isActive_)
      return *this;

    for (const auto& it : modes_)
      it->GetPrefix (*oStream_);

    *oStream_ << value;

    for (const auto& it : modes_)
      it->GetSuffix (*oStream_);

    return *this;
  }

  template <typename T>
  inline Logger& Logger::LogLine (const T& value)
  {
    if (!isActive_)
      return *this;

    for (const auto& it : modes_)
      it->GetPrefix (*oStream_);

    *oStream_ << value;

    for (const auto& it : modes_)
      it->GetSuffix (*oStream_);

    *oStream_ << std::endl;

    return *this;
  }
} // namespace yap

#endif // YAPOG_LOGGER_HXX
