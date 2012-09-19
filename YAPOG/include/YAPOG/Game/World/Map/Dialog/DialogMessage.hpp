#ifndef YAPOG_DIALOGMESSAGE_HPP
# define YAPOG_DIALOGMESSAGE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Dialog/IDialogMessage.hpp"

namespace yap
{
  class DialogMessage : public IDialogMessage
  {
    public:

      explicit DialogMessage (const String& content);

      virtual ~DialogMessage ();

      /// @name IDialogMessage members.
      /// @{
      virtual const String& GetContent () const;
      /// @}

    private:

      String content_;
  };
} // namespace yap

#endif // YAPOG_DIALOGMESSAGE_HPP
