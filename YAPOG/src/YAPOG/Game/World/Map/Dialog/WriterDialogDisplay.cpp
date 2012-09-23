#include "YAPOG/Game/World/Map/Dialog/WriterDialogDisplay.hpp"
#include "YAPOG/System/IO/IWriter.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogActor.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogMessage.hpp"

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
} // namespace yap
