#ifndef YAPOG_CLIENT_INFOBOX_HPP
# define YAPOG_CLIENT_INFOBOX_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "Gui/PokemonHPBarWidget.hpp"

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

    void Init ();

    void SetIsSelected (bool value);

    virtual bool IsFocusable () const;

  private:
    const Pokemon& pokemon_;
    bool isMainPokemon_;
    bool isSelected_;
    yap::WidgetBackground* normalBackground_;
    yap::WidgetBackground* selectedBackground_;
    yap::PictureBox* icon_;
    yap::Label* name_;
    yap::Label* level_;
    yap::PictureBox* gender_;
    PokemonHPBarWidget hpBar_;
    yap::Label* hpLabel_;

  };
} // namespace ycl

#endif // YAPOG_CLIENT_INFOBOX_HPP
