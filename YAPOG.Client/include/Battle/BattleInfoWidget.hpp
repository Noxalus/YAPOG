#ifndef YAPOG_CLIENT_BATTLEINFOWIDGET_HPP
# define YAPOG_CLIENT_BATTLEINFOWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/Label.hpp"
# include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
# include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
# include "YAPOG/Graphics/Texture.hpp"
# include "YAPOG/Game/Pokemon/Gender.hpp"

# include "Battle/BaseBattleWidget.hpp"
# include "Gui/PokemonHPBarWidget.hpp"

namespace yap
{
  class PictureBox;
  class PokemonExperience;
} // namespace yap

namespace ycl
{
  class IDrawableBattleEntity;

  class BattleInfoWidget : public BaseBattleWidget
  {
    DISALLOW_COPY (BattleInfoWidget);

  public:
    BattleInfoWidget (const yap::Padding& widgetPadding);

    virtual void Init ();

    virtual void UpdateHPBar ();

    void RefreshWidget ();

    /// @name Setters.
    /// @{
    void SetPokemon (const IDrawableBattleEntity& pokemon);
    /// @}

    virtual void HandleDraw (yap::IDrawingContext& context);
    virtual yap::Vector2 HandleGetSize () const;

  protected:
     /// @name Setters.
    /// @{
    virtual void SetHitPoint (const yap::HitPoint& hp);
    virtual void SetExperience (const yap::PokemonExperience& experience);
    /// @}

    /// @name Labels.
    /// @{
    yap::Label nameLabel_;
    yap::Label levelLabel_;
    /// @}

    /// @name Layouts.
    /// @{
    yap::VerticalLayout battleInfoBox_;
    yap::HorizontalLayout firstLine_;
    yap::HorizontalLayout nameBox_;
    yap::HorizontalLayout levelAndGenderBox_;
    yap::VerticalLayout levelBox_;
    yap::HorizontalLayout genderBox_;
    /// @}

    /// @name Picture boxes.
    /// @{
    yap::PictureBox* genderPictureBox_;
    /// @}

    // HP Bar
    PokemonHPBarWidget hpBar_;

    const IDrawableBattleEntity* pokemon_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_BATTLEINFOWIDGET_HPP