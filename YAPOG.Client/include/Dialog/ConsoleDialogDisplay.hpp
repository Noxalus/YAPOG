#ifndef YAPOG_CLIENT_CONSOLEDIALOGDISPLAY_HPP
# define YAPOG_CLIENT_CONSOLEDIALOGDISPLAY_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Dialog/IDialogDisplay.hpp"
# include "YAPOG/System/String.hpp"

namespace ycl
{
  class ConsoleDialogDisplay : public yap::IDialogDisplay
  {
      DISALLOW_COPY(ConsoleDialogDisplay);

    public:

      ConsoleDialogDisplay ();

      virtual ~ConsoleDialogDisplay ();

      /// @name IDialogDisplay members.
      /// @{
      virtual void Display (
        const yap::IDialogActor& actor,
        const yap::IDialogMessage& message);
      /// @}

    private:

      void PrintHeader (const yap::String& actorName);
      void PrintText (const yap::String& text);
  };
}

#endif // YAPOG_CLIENT_CONSOLEDIALOGDISPLAY_HPP
