#include "YAPOG/Graphics/Gui/GameInput/GameInput.hpp"

namespace yap
{
  GameInput::GameInput (GameInputType type, GameInputEntry::PtrType& entry)
    : type_ (type)
    , entries_ ()
  {
    AddEntry (entry);
  }

  void GameInput::AddEntry (GameInputEntry::PtrType& entry)
  {
    entries_.Add (entry);
  }

  bool GameInput::IsActive () const
  {
    for (const GameInputEntry::PtrType& entry : entries_)
      if (entry->IsActive ())
        return true;

    return false;
  }

  bool GameInput::IsTriggered () const
  {
    for (const GameInputEntry::PtrType& entry : entries_)
      if (entry->IsTriggered ())
        return true;

    return false;
  }

  void GameInput::BeginUpdate ()
  {
    for (const GameInputEntry::PtrType& entry : entries_)
      entry->BeginUpdate ();
  }

  void GameInput::Update (const GuiEvent& guiEvent)
  {
    for (const GameInputEntry::PtrType& entry : entries_)
      entry->Update (guiEvent);
  }

  void GameInput::EndUpdate ()
  {
    for (const GameInputEntry::PtrType& entry : entries_)
      entry->EndUpdate ();
  }
} /// namespace yap
