#ifndef YAPOG_CLIENT_POKEMONEXPERIENCEBARWIDGET_HPP
# define YAPOG_CLIENT_POKEMONEXPERIENCEBARWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"

namespace yap
{
  class PictureBox;
  class HorizontalLayout;
}

namespace ycl
{
  class Pokemon;

  class PokemonExperienceBarWidget : public yap::BaseWidget
  {
  public:
    PokemonExperienceBarWidget (const Pokemon& pokemon);

    virtual bool IsFocusable () const;

  protected:
    virtual void HandleMove (const yap::Vector2& offset);
    virtual void HandleScale (const yap::Vector2& factor);
    virtual void HandleDraw (yap::IDrawingContext& offset);
    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);
    virtual void HandleUpdate (const yap::Time& dt);

  private:
    const Pokemon& pokemon_;
    yap::PictureBox* experienceBarContent_;
    yap::HorizontalLayout* mainLayout_;

  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONEXPERIENCEBARWIDGET_HPP
