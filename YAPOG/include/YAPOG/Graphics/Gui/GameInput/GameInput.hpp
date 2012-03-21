#ifndef YAPOG_GAMEINPUT_HPP
# define YAPOG_GAMEINPUT_HPP

# include "YAPOG/Export.hpp"
# include "YAPOG/Graphics/Gui/GameInput/GameInputType.hpp"
# include "YAPOG/Graphics/Gui/GameInput/GameInputEntry.hpp"
# include "YAPOG/Collection/List.hpp"

namespace yap
{
  class GameInput
  {
    public:

      GameInput (GameInputType type, GameInputEntry::PtrType& entry);

      void AddEntry (GameInputEntry::PtrType& entry);

      bool IsActive () const;
      bool IsTriggered () const;

      void BeginUpdate ();
      void Update (const GuiEvent& guiEvent);
      void EndUpdate ();

    private:

      GameInputType type_;

      List<GameInputEntry::PtrType> entries_;
  };
} /// namespace yap

#endif /// !YAPOG_GAMEINPUT_HPP
