#ifndef YAPOG_IDIALOGMESSAGE_HPP
# define YAPOG_IDIALOGMESSAGE_HPP

# include "YAPOG/Game/Factory/ICloneable.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  struct IDialogMessage : public ICloneable
  {
      virtual ~IDialogMessage () { }

      virtual const yap::String& GetContent () const = 0;

      /// @name ICloneable members.
      /// @{
      virtual IDialogMessage* Clone () const { return nullptr; }
      /// @}
  };
} // namespace yap

#endif // YAPOG_IDIALOGMESSAGE_HPP
