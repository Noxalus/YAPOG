#ifndef YAPOG_GAMEINPUTENTRY_HPP
# define YAPOG_GAMEINPUTENTRY_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/GuiEvent.hpp"

namespace yap
{
  class YAPOG_LIB GameInputEntry
  {
      DISALLOW_COPY(GameInputEntry);

    public:

      GameInputEntry ();
      virtual ~GameInputEntry ();

      bool IsActive () const;
      bool IsActivated () const;
      bool IsDeactivated () const;

      bool IsActive (const GuiEvent& guiEvent) const;
      bool IsActivated (const GuiEvent& guiEvent) const;
      bool IsDeactivated (const GuiEvent& guiEvent) const;

      void BeginUpdate ();
      virtual void Update (const GuiEvent& guiEvent) = 0;
      void EndUpdate ();

    protected:

      void Activate (bool isActive);

    private:

      /// @brief Checks that the event parameters (key, mouse button...)
      /// correpond to this game input entry.
      virtual bool GuiEventIsCompatible (const GuiEvent& guiEvent) const = 0;

      bool isActive_;
      bool previousIsActive_;
  };
} // namespace yap

#endif // YAPOG_GAMEINPUTENTRY_HPP
