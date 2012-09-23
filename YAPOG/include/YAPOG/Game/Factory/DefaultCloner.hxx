#ifndef YAPOG_DEFAULTCLONER_HXX
# define YAPOG_DEFAULTCLONER_HXX

namespace yap
{
  template <typename T>
  inline DefaultCloner<T>::DefaultCloner ()
  {
  }

  template <typename T>
  inline DefaultCloner<T>::~DefaultCloner ()
  {
  }

  template <typename T>
  inline T* DefaultCloner<T>::Clone (const T& object) const
  {
    return object.Clone ();
  }
} // namespace yap

#endif // YAPOG_DEFAULTCLONER_HXX
