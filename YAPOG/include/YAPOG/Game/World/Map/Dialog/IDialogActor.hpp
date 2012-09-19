#ifndef YAPOG_IDIALOGACTOR_HPP
# define YAPOG_IDIALOGACTOR_HPP

# include "YAPOG/System/String.hpp"

namespace yap
{
  struct IDialogActor
  {
      virtual ~IDialogActor () { }

      virtual const String& GetName () const = 0;
  };
} // namespace yap

#endif // YAPOG_IDIALOGACTOR_HPP
