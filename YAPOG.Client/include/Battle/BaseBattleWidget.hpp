#ifndef YAPOG_CLIENT_BASEBATTLEWIDGET_HPP
# define YAPOG_CLIENT_BASEBATTLEWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"

namespace yap
{
  struct ISprite;
  struct IDrawingContext;

  class DialogBoxWidget;
  class WidgetBackground;
  class Time;
} // namespace yap

namespace ycl
{
  class IDrawableBattleEntity;

  class BaseBattleWidget : public yap::BaseWidget
  {
  public:
    BaseBattleWidget ();

    virtual void SetPokemon (const IDrawableBattleEntity& pokemon) = 0;
    virtual void Init () = 0;

    virtual bool IsFocusable () const;
  protected:
    virtual void HandleMove (const yap::Vector2& offset);
    virtual void HandleScale (const yap::Vector2& factor);
    virtual void HandleDraw (yap::IDrawingContext& context);
    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);
    virtual void HandleUpdate (const yap::Time& dt);
  };
} // namespace ycl

#endif // YAPOG_CLIENT_BASEBATTLEWIDGET_HPP
