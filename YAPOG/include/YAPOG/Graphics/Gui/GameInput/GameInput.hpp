#ifndef YAPOG_GAMEINPUT_HPP
# define YAPOG_GAMEINPUT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/GameInput/GameInputType.hpp"
# include "YAPOG/Graphics/Gui/GameInput/GameInputEntry.hpp"
# include "YAPOG/Collection/PtrList.hpp"

namespace yap
{
  class YAPOG_LIB GameInput
  {
    public:

      DECLARE_PTR_TYPE(GameInput);
      DISALLOW_COPY(GameInput);

      GameInput (GameInputType type, GameInputEntry* entry);

      void AddEntry (GameInputEntry* entry);

      bool IsActive () const;
      bool IsActivated () const;
      bool IsDeactivated () const;

      void BeginUpdate ();
      void Update (const GuiEvent& guiEvent);
      void EndUpdate ();

      GameInputType GetType () const;

    private:

      GameInputType type_;

      PtrList<GameInputEntry> entries_;
  };
} // namespace yap

#endif // YAPOG_GAMEINPUT_HPP
