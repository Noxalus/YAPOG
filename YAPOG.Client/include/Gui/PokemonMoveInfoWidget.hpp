#ifndef YAPOG_CLIENT_POKEMONMOVEINFOWIDGET_HPP
# define YAPOG_CLIENT_POKEMONMOVEINFOWIDGET_HPP

# include "YAPOG/Macros.hpp"

# include "Gui/PokemonFrontInfoWidget.hpp"
# include "Gui/PokemonSingleMoveInfoWidget.hpp"
# include "Gui/IPokemonSummaryWidget.hpp"

namespace yap
{
  class PictureBox;
  class Label;
  class VerticalLayout;
}

namespace ycl
{
  class Pokemon;
  class PokemonSingleMoveInfoWidget;

  class PokemonMoveInfoWidget : public IPokemonSummaryWidget
  {
  public:
    PokemonMoveInfoWidget ();

    void Init (const Pokemon& pokemon);

    virtual bool IsFocusable () const;

  protected:
    virtual void HandleMove (const yap::Vector2& offset);
    virtual void HandleScale (const yap::Vector2& factor);
    virtual void HandleDraw (yap::IDrawingContext& offset);
    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);
    virtual void HandleUpdate (const yap::Time& dt);

  private:
    // Labels
    yap::Label* name_;
    yap::Label* level_;

    // PictureBoxes
    yap::PictureBox* gender_;
    yap::PictureBox* spriteFront_;

    // Layouts
    yap::VerticalLayout* mainLayout_;

    yap::HorizontalLayout* firstLine_;
    yap::VerticalLayout* firstLinePartRight_;

    PokemonFrontInfoWidget pokemonFrontInfoWidget_;
    yap::collection::Array<PokemonSingleMoveInfoWidget*> 
      pokemonSingleMoveInfoWidgets_;

  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONMOVEINFOWIDGET_HPP
