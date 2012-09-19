#ifndef YAPOG_IDIALOGMESSAGE_HPP
# define YAPOG_IDIALOGMESSAGE_HPP

# include "YAPOG/System/String.hpp"

namespace yap
{
  struct IDialogMessage
  {
      virtual ~IDialogMessage () { }

      virtual const yap::String& GetContent () const = 0;
  };
} // namespace yap

#endif // YAPOG_IDIALOGMESSAGE_HPP
