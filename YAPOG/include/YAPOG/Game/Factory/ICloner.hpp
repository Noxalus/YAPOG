#ifndef YAPOG_ICLONER_HPP
# define YAPOG_ICLONER_HPP

namespace yap
{
  template <typename T>
  struct ICloner
  {
      virtual ~ICloner () { }

      virtual T* Clone (const T& object) const = 0;
  };
} // namespace yap

#endif // YAPOG_ICLONER_HPP
