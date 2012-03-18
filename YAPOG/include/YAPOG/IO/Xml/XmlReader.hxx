#ifndef YAPOG_XMLREADER_HXX
# define YAPOG_XMLREADER_HXX

namespace yap
{
  template <typename T>
  inline const T XmlReader::Get (const String& name) const
  {
    return data_->get<T> (name);
  }
} /// namespace yap

#endif /// !YAPOG_XMLREADER_HXX
