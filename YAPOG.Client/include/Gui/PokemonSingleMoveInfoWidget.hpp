#ifndef YAPOG_CLIENT_POKEMONSINGLEMOVENFOWIDGET_HPP
# define YAPOG_CLIENT_POKEMONSINGLEMOVENFOWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"

namespace yap
{
  class PictureBox;
  class Label;
  class HorizontalLayout;
  class VerticalLayout;
  class PokemonMove;
}

namespace ycl
{
  class Pokemon;

  class PokemonSingleMoveInfoWidget : public yap::BaseWidget
  {
  public:
    PokemonSingleMoveInfoWidget (const yap::PokemonMove& move);

    void Init ();

    virtual bool IsFocusable () const;

  protected:
    virtual void HandleMove (const yap::Vector2& offset);
    virtual void HandleScale (const yap::Vector2& factor);
    virtual void HandleDraw (yap::IDrawingContext& offset);
    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);
    virtual void HandleUpdate (const yap::Time& dt);

  private:
    const yap::PokemonMove& move_;

    // Labels
    yap::Label* name_;
    yap::Label* pp_;

    // PictureBoxes
    yap::PictureBox* type_;

    // Layouts
    yap::VerticalLayout* mainLayout_;
    yap::HorizontalLayout* nameAndTypeLayout_;
    yap::VerticalLayout* ppLayout_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONSINGLEMOVENFOWIDGET_HPP
