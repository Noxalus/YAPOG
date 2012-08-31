#ifndef YAPOG_CLIENT_POKEMONSTATSINFOWIDGET_HPP
# define YAPOG_CLIENT_POKEMONSTATSINFOWIDGET_HPP

# include "YAPOG/Macros.hpp"

# include "Gui/PokemonFrontInfoWidget.hpp"
# include "Gui/PokemonExperienceBarWidget.hpp"
# include "Gui/IPokemonSummaryWidget.hpp"

namespace ycl
{
  class Pokemon;

  class PokemonStatsInfoWidget : public IPokemonSummaryWidget
  {
  public:
    PokemonStatsInfoWidget ();

    virtual void Init ();

    virtual void SetPokemon (const Pokemon& pokemon);

    /// @name IWidget members.
    /// {
    /*
    virtual void SetDefaultColor (const sf::Color& color);
    virtual void AddDrawable (yap::IDrawable& drawable);
    virtual void AddChild (yap::IWidget& child);
    virtual yap::IWidget& GetRoot () const;
    virtual yap::WidgetBorder* GetBorder () const;
    virtual void SetParent (yap::IWidget& parent);
    virtual void SetPadding (const yap::Padding& padding);
    virtual void SetBackground (yap::WidgetBackground& background);
    virtual void SetBorder  (yap::WidgetBorder& border, yap::uint width);
    virtual void Refresh ();
    */
    virtual bool IsFocusable () const;
    /*
    virtual void SetFocused (bool state);
    virtual void SetEnable (bool enable);
    virtual void Open ();
    virtual void Close ();
    */
    /// }

  protected:
    virtual void HandleMove (const yap::Vector2& offset);
    virtual void HandleScale (const yap::Vector2& factor);
    virtual void HandleDraw (yap::IDrawingContext& offset);
    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);
    virtual void HandleUpdate (const yap::Time& dt);

  private:
    // Labels
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
    yap::PictureBox* type1_;
    yap::PictureBox* type2_;

    // Layouts
    yap::VerticalLayout* mainLayout_;

    yap::HorizontalLayout* firstLine_;

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

    PokemonFrontInfoWidget pokemonFrontInfoWidget_;
    PokemonExperienceBarWidget experienceBarWidget_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONSTATSINFOWIDGET_HPP
