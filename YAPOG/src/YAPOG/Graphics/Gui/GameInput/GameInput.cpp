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
    for (const auto it : entries_)
      delete it;
  }

  void GameInput::AddEntry (GameInputEntry* entry)
  {
    entries_.Add (entry);
  }

  bool GameInput::IsActive () const
  {
    for (const auto it : entries_)
      if (it->IsActive ())
        return true;

    return false;
  }

  bool GameInput::IsActivated () const
  {
    for (const auto it : entries_)
      if (it->IsActivated ())
        return true;

    return false;
  }

  bool GameInput::IsDeactivated () const
  {
    for (const auto it : entries_)
      if (it->IsDeactivated ())
        return true;

    return false;
  }

  void GameInput::BeginUpdate ()
  {
    for (const auto it : entries_)
      it->BeginUpdate ();
  }

  void GameInput::Update (const GuiEvent& guiEvent)
  {
    for (const auto it : entries_)
      it->Update (guiEvent);
  }

  void GameInput::EndUpdate ()
  {
    for (const auto it : entries_)
      it->EndUpdate ();
  }

  GameInputType GameInput::GetType () const
  {
    return type_;
  }
} // namespace yap
