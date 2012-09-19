#ifndef YAPOG_IGAMEREQUIREMENT_HPP
# define YAPOG_IGAMEREQUIREMENT_HPP

namespace yap
{
  struct IGameRequirement
  {
      virtual ~IGameRequirement () { }

      virtual bool IsFulfilled () = 0;
  };
} // namespace yap

#endif // YAPOG_IGAMEREQUIREMENT_HPP
