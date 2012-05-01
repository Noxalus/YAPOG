#ifndef YAPOG_TESTSCREEN_HPP
# define YAPOG_TESTSCREEN_HPP

# include "YAPOG/Graphics/Game/GameScreen.hpp"
# include "YAPOG/Graphics/Gui/GuiManager.hpp"
# include "YAPOG/Graphics/Texture.hpp"
# include "YAPOG/Collection/List.hpp"
# include "YAPOG/Graphics/Game/Sprite/RegularAnimatedSprite.hpp"
# include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"

namespace ycl
{
  class TestScreen : public yap::GameScreen
  {
    public:

      TestScreen ();
      virtual ~TestScreen ();

      virtual const yap::ScreenType& HandleRun (
        const yap::Time& dt,
        yap::IDrawingContext& context);

      virtual void HandleInit ();

      virtual void HandleActivate ();
      virtual void HandleDeactivate ();

      virtual bool HandleOnEvent (const yap::GuiEvent& guiEvent);
      virtual bool HandleOnPriorityEvent (const yap::GuiEvent& guiEvent);

    private:

      yap::collection::List<yap::Texture*> textures_;
      yap::collection::List<yap::Texture*> backTextures_;

      yap::Sprite spr1_;
//    yap::RegularAnimatedSprite anim1_;
  };
} // namespace ycl

#endif // YAPOG_TESTSCREEN_HPP
