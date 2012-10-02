#ifndef YAPOG_IDIALOGRESPONSE_HPP
# define YAPOG_IDIALOGRESPONSE_HPP

# include "YAPOG/Game/Factory/ICloneable.hpp"

namespace yap
{
  struct IDialogResponse : public ICloneable
  {
      virtual ~IDialogResponse () { }

      /// @name ICloneable members.
      /// @{
      virtual IDialogResponse* Clone () const { return nullptr; }
      /// @}
  };
} // namespace yap

#endif // YAPOG_IDIALOGRESPONSE_HPP
