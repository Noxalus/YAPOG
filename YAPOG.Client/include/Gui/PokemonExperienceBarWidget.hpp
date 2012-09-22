#ifndef YAPOG_CLIENT_POKEMONEXPERIENCEBARWIDGET_HPP
# define YAPOG_CLIENT_POKEMONEXPERIENCEBARWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/ProgressBarWidget.hpp"

namespace yap
{
  class PictureBox;
  class HorizontalLayout;
}

namespace ycl
{
  class Pokemon;

  class PokemonExperienceBarWidget : public yap::ProgressBarWidget
  {
  public:
    PokemonExperienceBarWidget ();

    void Init ();

    void SetPokemon (const Pokemon& pokemon);

    virtual bool IsFocusable () const;

  protected:
    virtual void HandleMove (const yap::Vector2& offset);
    virtual void HandleScale (const yap::Vector2& factor);
    virtual void HandleDraw (yap::IDrawingContext& offset);
    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);
    virtual void HandleUpdate (const yap::Time& dt);

  private:
    yap::PictureBox* experienceBarContent_;
    yap::HorizontalLayout* mainLayout_;

  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONEXPERIENCEBARWIDGET_HPP
