#include "Dialog/ConsoleDialogDisplay.hpp"

#include "YAPOG/Game/World/Map/Dialog/IDialogMessage.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogActor.hpp"

namespace ycl
{
  ConsoleDialogDisplay::ConsoleDialogDisplay ()
  {
  }

  ConsoleDialogDisplay::~ConsoleDialogDisplay ()
  {
  }

  void ConsoleDialogDisplay::Display (
    const yap::IDialogActor& actor,
    const yap::IDialogMessage& message)
  {
    PrintHeader (actor.GetName ());

    PrintText (message.GetContent ());
  }

  void ConsoleDialogDisplay::PrintHeader (const yap::String& actorName)
  {
    std::cout << "["
              << actorName
              << "] ";
  }

  void ConsoleDialogDisplay::PrintText (const yap::String& text)
  {
    std::cout << "Dialog message: "
              << text
              << std::endl;
  }
} // namespace ycl
