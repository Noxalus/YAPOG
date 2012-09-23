#ifndef YAPOG_CLIENT_POKEMONEXPERIENCEBARWIDGET_HPP
# define YAPOG_CLIENT_POKEMONEXPERIENCEBARWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/ProgressBarWidget.hpp"

namespace yap
{
  class PictureBox;
  class HorizontalLayout;
  class PokemonExperience;
}

namespace ycl
{
  class PokemonExperienceBarWidget : public yap::ProgressBarWidget
  {
  public:
    PokemonExperienceBarWidget ();

    void Init ();

    void SetExperience (const yap::PokemonExperience& experience);

    virtual void UpdateProgressBar ();

    virtual bool IsFocusable () const;

  protected:
    virtual void HandleMove (const yap::Vector2& offset);
    virtual void HandleScale (const yap::Vector2& factor);
    virtual void HandleDraw (yap::IDrawingContext& offset);
    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

  private:
    virtual void RealUpdate ();

    const yap::PokemonExperience* experience_;

    static const float MAX_EXP_BAR_SIZE;

  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONEXPERIENCEBARWIDGET_HPP
