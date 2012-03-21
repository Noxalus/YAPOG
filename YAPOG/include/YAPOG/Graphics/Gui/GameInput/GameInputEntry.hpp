#ifndef YAPOG_GAMEINPUTENTRY_HPP
# define YAPOG_GAMEINPUTENTRY_HPP

# include <memory>

# include "YAPOG/Export.hpp"
# include "YAPOG/Graphics/Gui/GuiEvent.hpp"

namespace yap
{
  class GameInputEntry
  {
    public:

      typedef std::shared_ptr<GameInputEntry> PtrType;

      GameInputEntry ();
      virtual ~GameInputEntry ();

      bool IsActive () const;
      bool IsTriggered () const;

      void BeginUpdate ();
      virtual void Update (const GuiEvent& guiEvent) = 0;
      void EndUpdate ();

    protected:

      void Activate (bool isActive);

    private:

      bool isActive_;
      bool previousIsActive_;
  };
} /// namespace yap

#endif /// !YAPOG_GAMEINPUTENTRY_HPP
