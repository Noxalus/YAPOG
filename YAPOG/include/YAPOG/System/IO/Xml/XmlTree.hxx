#ifndef YAPOG_XMLTREE_HXX
# define YAPOG_XMLTREE_HXX

namespace yap
{
  template <typename T>
  inline const T XmlTree::Get (const String& name) const
  {
    return data_->get<T> (name);
  }

  template <typename T>
  inline const T XmlTree::Get () const
  {
    return data_->get_value <T> ();
  }

  template <typename T>
  inline void XmlTree::Add (const String& name, const T& value)
  {
    data_->put (name, value);
  }
} // namespace yap

#endif // YAPOG_XMLTREE_HXX
