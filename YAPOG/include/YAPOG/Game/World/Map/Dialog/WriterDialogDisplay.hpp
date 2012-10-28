#ifndef YAPOG_WRITERDIALOGDISPLAY_HPP
# define YAPOG_WRITERDIALOGDISPLAY_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Dialog/IDialogDisplay.hpp"

namespace yap
{
  struct IWriter;

  class YAPOG_LIB WriterDialogDisplay : public IDialogDisplay
  {
      DISALLOW_COPY(WriterDialogDisplay);

    public:

      explicit WriterDialogDisplay (IWriter& writer);

      virtual ~WriterDialogDisplay ();

      /// @name IDialogDisplay members.
      /// @{
      virtual void Display (
        const IDialogActor& dialogActor,
        const IDialogMessage& dialogMessage);

      virtual void Display (
        const IDialogActor& actor,
        const collection::Array<IDialogResponse*>& responses);

      virtual Event<IDialogDisplay&, const ID&>& OnResponseReceivedEvent ();
      /// @}

      /// @name Events.
      /// @{
      Event<IDialogDisplay&, const ID&> OnResponseReceived;
      /// @}

    private:

      IWriter& writer_;
  };
} // namespace yap

#endif // YAPOG_WRITERDIALOGDISPLAY_HPP
