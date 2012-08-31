#ifndef YAPOG_CLIENT_POKEMONBASICINFOWIDGET_HPP
# define YAPOG_CLIENT_POKEMONBASICINFOWIDGET_HPP

# include "YAPOG/Macros.hpp"

# include "Gui/PokemonFrontInfoWidget.hpp"
# include "Gui/IPokemonSummaryWidget.hpp"

namespace yap
{
  class PictureBox;
  class Label;
  class MultiLabelWidget;
  class HorizontalLayout;
  class VerticalLayout;
}

namespace ycl
{
  class Pokemon;

  class PokemonBasicInfoWidget : public IPokemonSummaryWidget
  {
  public:
    PokemonBasicInfoWidget ();

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
    yap::Label* name_;
    yap::Label* staticID_;
    yap::Label* trainerName_;
    yap::Label* uniqueID_;
    yap::Label* item_;
    yap::MultiLabelWidget* nature_;

    // PictureBoxes
    yap::PictureBox* type1_;
    yap::PictureBox* type2_;

    // Layouts
    yap::VerticalLayout* mainLayout_;

    yap::HorizontalLayout* firstLine_;

    yap::VerticalLayout* firstLinePartRight_;
    yap::HorizontalLayout* typesLayout_;

    yap::VerticalLayout* secondLine_;

    PokemonFrontInfoWidget pokemonFrontInfoWidget_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONBASICINFOWIDGET_HPP
