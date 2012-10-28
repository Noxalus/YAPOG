#ifndef YAPOG_IDIALOGRESPONSE_HPP
# define YAPOG_IDIALOGRESPONSE_HPP

# include "YAPOG/Game/Factory/ICloneable.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  struct IDialogResponse : public ICloneable
  {
      virtual ~IDialogResponse () { }

      virtual const String& GetMessageContent () const = 0;

      /// @name ICloneable members.
      /// @{
      virtual IDialogResponse* Clone () const { return nullptr; }
      /// @}
  };
} // namespace yap

#endif // YAPOG_IDIALOGRESPONSE_HPP
