#ifndef YAPOG_GAMEINPUTENTRY_HPP
# define YAPOG_GAMEINPUTENTRY_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/GuiEvent.hpp"

namespace yap
{
  class YAPOG_LIB GameInputEntry
  {
    public:

      DISALLOW_COPY(GameInputEntry);

      GameInputEntry ();
      virtual ~GameInputEntry ();

      bool IsActive () const;
      bool IsActivated () const;
      bool IsDeactivated () const;

      void BeginUpdate ();
      virtual void Update (const GuiEvent& guiEvent) = 0;
      void EndUpdate ();

    protected:

      void Activate (bool isActive);

    private:

      bool isActive_;
      bool previousIsActive_;
  };
} // namespace yap

#endif // YAPOG_GAMEINPUTENTRY_HPP
