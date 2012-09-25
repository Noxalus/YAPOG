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
    PokemonInfoBox (const Pokemon& pokemon, bool isMainPokemon);

    void Init ();

    void SetIsSelected (bool value);

    virtual bool IsFocusable () const;

    void RefreshWidget ();

  private:
    bool initialized_;
    const Pokemon& pokemon_;
    bool isMainPokemon_;
    bool isSelected_;
    yap::WidgetBackground* normalBackground_;
    yap::WidgetBackground* selectedBackground_;
    yap::Label* name_;
    yap::Label* level_;
    yap::Label* hpLabel_;
    yap::PictureBox* gender_;
    yap::PictureBox* icon_;
    PokemonHPBarWidget hpBar_;

    static const yap::String DEFAULT_ICON_FILE;
    static const yap::String DEFAULT_GENDER_FILE;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_INFOBOX_HPP
