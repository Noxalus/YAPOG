#include "YAPOG/Graphics/Gui/GameInput/GameInput.hpp"

namespace yap
{
  GameInput::GameInput (GameInputType type, GameInputEntry* entry)
    : type_ (type)
    , entries_ ()
  {
    AddEntry (entry);
  }

  GameInput::~GameInput ()
  {
    for (const GameInputEntry* it : entries_)
      delete it;
  }

  void GameInput::AddEntry (GameInputEntry* entry)
  {
    entries_.Add (entry);
  }

  bool GameInput::IsActive () const
  {
    for (const GameInputEntry* it : entries_)
      if (it->IsActive ())
        return true;

    return false;
  }

  bool GameInput::IsActivated () const
  {
    for (const GameInputEntry* it : entries_)
      if (it->IsActivated ())
        return true;

    return false;
  }

  bool GameInput::IsDeactivated () const
  {
    for (const GameInputEntry* it : entries_)
      if (it->IsDeactivated ())
        return true;

    return false;
  }

  bool GameInput::IsActive (const GuiEvent& guiEvent) const
  {
    for (const GameInputEntry* it : entries_)
      if (it->IsActive (guiEvent))
        return true;

    return false;
  }

  bool GameInput::IsActivated (const GuiEvent& guiEvent) const
  {
    for (const GameInputEntry* it : entries_)
      if (it->IsActivated (guiEvent))
        return true;

    return false;
  }

  bool GameInput::IsDeactivated (const GuiEvent& guiEvent) const
  {
    for (const GameInputEntry* it : entries_)
      if (it->IsDeactivated (guiEvent))
        return true;

    return false;
  }

  void GameInput::BeginUpdate ()
  {
    for (GameInputEntry* it : entries_)
      it->BeginUpdate ();
  }

  void GameInput::Update (const GuiEvent& guiEvent)
  {
    for (GameInputEntry* it : entries_)
      it->Update (guiEvent);
  }

  void GameInput::EndUpdate ()
  {
    for (GameInputEntry* it : entries_)
      it->EndUpdate ();
  }

  GameInputType GameInput::GetType () const
  {
    return type_;
  }
} // namespace yap
