#include "YAPOG/Game/World/Map/Dialog/WriterDialogDisplay.hpp"
#include "YAPOG/System/IO/IWriter.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogActor.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogMessage.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogResponse.hpp"
#include "YAPOG/System/StringHelper.hpp"

namespace yap
{
  WriterDialogDisplay::WriterDialogDisplay (IWriter& writer)
    : writer_ (writer)
  {
  }

  WriterDialogDisplay::~WriterDialogDisplay ()
  {
  }

  void WriterDialogDisplay::Display (
    const IDialogActor& dialogActor,
    const IDialogMessage& dialogMessage)
  {
    writer_.Write (
      "[" +
      dialogActor.GetName () +
      "] " +
      dialogMessage.GetContent () +
      "\n");
  }

  void WriterDialogDisplay::Display (
    const IDialogActor& dialogActor,
    const collection::Array<IDialogResponse*>& responses)
  {
    for (UInt64 count = 0; count < responses.Count (); ++count)
    {
      writer_.Write (
        "[" +
        dialogActor.GetName () +
        "] [" +
        StringHelper::ToString (count) +
        "] [" +
        responses[count]->GetMessageContent () +
        "]\n");
    }

    writer_.Write (String ("Pick your choice: "));

    /// @warning [TMP]
    ID::ValueType responseIDValue;
    std::cin >> responseIDValue;

    OnResponseReceivedEvent () (*this, ID (responseIDValue));
  }

  Event<IDialogDisplay&, const ID&>&
  WriterDialogDisplay::OnResponseReceivedEvent ()
  {
    return OnResponseReceived;
  }
} // namespace yap
