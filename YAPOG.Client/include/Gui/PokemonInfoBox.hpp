#ifndef YAPOG_CLIENT_INFOBOX_HPP
# define YAPOG_CLIENT_INFOBOX_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"

namespace yap
{
  class PictureBox;
  class Label;
  class VerticalLayout;
}

namespace ycl
{
  class Pokemon;

  class PokemonInfoBox : public yap::BaseWidget
  {
  public:
    PokemonInfoBox (
      bool isMainPokemon, 
      const Pokemon& pokemon);

    virtual bool IsFocusable () const;

  private:
    yap::PictureBox* icon_;
    yap::Label* name_;
    yap::Label* level_;
    yap::PictureBox* gender_;
    yap::PictureBox* hpBar_;
    yap::PictureBox* hpBarContent_;
    yap::Label* hpLabel_;
    yap::VerticalLayout* vlayout_;
    bool isMainPokemon_;

  protected:
    virtual void HandleMove (const yap::Vector2& offset);
    virtual void HandleScale (const yap::Vector2& factor);
    virtual void HandleDraw (yap::IDrawingContext& offset);
    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);
    virtual void HandleUpdate (const yap::Time& dt);

  };
} // namespace ycl

#endif // YAPOG_CLIENT_INFOBOX_HPP
