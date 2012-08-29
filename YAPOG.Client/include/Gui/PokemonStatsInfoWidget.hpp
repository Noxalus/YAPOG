#ifndef YAPOG_CLIENT_POKEMONSTATSINFOWIDGET_HPP
# define YAPOG_CLIENT_POKEMONSTATSINFOWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"

# include "Gui/PokemonExperienceBarWidget.hpp"

namespace ycl
{
  class Pokemon;

  class PokemonStatsInfoWidget : public yap::BaseWidget
  {
  public:
    PokemonStatsInfoWidget (const Pokemon& pokemon);

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
    const Pokemon& pokemon_;

    // Labels
    yap::Label* nameLeft_;
    yap::Label* level_;
    yap::Label* hp_;
    yap::Label* attack_;
    yap::Label* defense_;
    yap::Label* specialAttack_;
    yap::Label* specialDefense_;
    yap::Label* speed_;
    yap::Label* experiencePointLabel_;
    yap::Label* experiencePoint_;
    yap::Label* nextLevelPointLabel_;
    yap::Label* nextLevelPoint_;


    // PictureBoxes
    yap::PictureBox* gender_;
    yap::PictureBox* spriteFront_;
    yap::PictureBox* type1_;
    yap::PictureBox* type2_;

    // Layouts
    yap::VerticalLayout* mainLayout_;

    yap::HorizontalLayout* firstLine_;

    yap::VerticalLayout* firstLinePartLeft_;
    yap::VerticalLayout* levelLayout_;
    yap::VerticalLayout* nameLayout_;
    yap::HorizontalLayout* genderLayout_;
    yap::HorizontalLayout* levelNameGenderLayout_;
    yap::VerticalLayout* spriteFrontLayout_;

    yap::VerticalLayout* firstLinePartRight_;
    yap::VerticalLayout* hpLayout_;
    yap::VerticalLayout* statsLayout_;

    yap::VerticalLayout* experienceLayout_;
    yap::HorizontalLayout* experiencePointLayout_;
    yap::VerticalLayout* experiencePointLabelLayout_;
    yap::VerticalLayout* experiencePointNumberLayout_;
    yap::HorizontalLayout* nextLevelPointLayout_;
    yap::VerticalLayout* nextLevelPointLabelLayout_;
    yap::VerticalLayout* nextLevelPointNumberLayout_;

    yap::VerticalLayout* capacityAndExperienceGlobalLayout_;
    yap::HorizontalLayout* capacityAndExperienceLayout_;
    yap::VerticalLayout* capacityLayout_;
    yap::VerticalLayout* experienceBarLayout_;

    PokemonExperienceBarWidget experienceBar_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONSTATSINFOWIDGET_HPP
