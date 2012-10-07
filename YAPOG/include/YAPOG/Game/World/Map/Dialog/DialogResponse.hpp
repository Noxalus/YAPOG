#ifndef YAPOG_DIALOGRESPONSE_HPP
# define YAPOG_DIALOGRESPONSE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Dialog/IDialogResponse.hpp"

namespace yap
{
  class DialogResponse : public IDialogResponse
  {
      DISALLOW_ASSIGN(DialogResponse);

    public:

      explicit DialogResponse (const String& messageContent);

      virtual ~DialogResponse ();

      /// @name ICloneable members.
      /// @{
      virtual DialogResponse* Clone () const;
      /// @}

      /// @name IDialogResponse members.
      /// @{
      virtual const String& GetMessageContent () const;
      /// @}

    protected:

      DialogResponse (const DialogResponse& copy);

    private:

      String messageContent_;
  };
} // namespace yap

#endif // YAPOG_DIALOGRESPONSE_HPP
