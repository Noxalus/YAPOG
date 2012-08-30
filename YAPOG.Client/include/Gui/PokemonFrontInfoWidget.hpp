#ifndef YAPOG_CLIENT_POKEMONFRONTINFOWIDGET_HPP
# define YAPOG_CLIENT_POKEMONFRONTINFOWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"

namespace yap
{
  class PictureBox;
  class Label;
  class HorizontalLayout;
  class VerticalLayout;
}

namespace ycl
{
  class Pokemon;

  class PokemonFrontInfoWidget : public yap::BaseWidget
  {
  public:
    PokemonFrontInfoWidget ();

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
    yap::VerticalLayout* levelLayout_;
    yap::VerticalLayout* nameLayout_;
    yap::HorizontalLayout* genderLayout_;
    yap::HorizontalLayout* levelNameGenderLayout_;
    yap::VerticalLayout* spriteFrontLayout_;

    // Sprite
    yap::ISprite* genderMaleIcon_;
    yap::ISprite* genderFemaleIcon_;

  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONFRONTINFOWIDGET_HPP
