#ifndef YAPOG_GAMEINPUT_HPP
# define YAPOG_GAMEINPUT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/GameInput/GameInputType.hpp"
# include "YAPOG/Graphics/Gui/GameInput/GameInputEntry.hpp"
# include "YAPOG/Collection/List.hpp"

namespace yap
{
  /// @brief Represents a game input action of the player.
  class YAPOG_LIB GameInput
  {
      DISALLOW_COPY(GameInput);

    public:

      GameInput (GameInputType type, GameInputEntry* entry);
      ~GameInput ();

      void AddEntry (GameInputEntry* entry);

      bool IsActive () const;
      bool IsActivated () const;
      bool IsDeactivated () const;

      bool IsActive (const GuiEvent& guiEvent) const;
      bool IsActivated (const GuiEvent& guiEvent) const;
      bool IsDeactivated (const GuiEvent& guiEvent) const;

      void BeginUpdate ();
      void Update (const GuiEvent& guiEvent);
      void EndUpdate ();

      GameInputType GetType () const;

    private:

      GameInputType type_;

      collection::List<GameInputEntry*> entries_;
  };
} // namespace yap

#endif // YAPOG_GAMEINPUT_HPP
