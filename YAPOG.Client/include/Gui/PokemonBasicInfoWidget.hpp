#ifndef YAPOG_CLIENT_POKEMONBASICINFOWIDGET_HPP
# define YAPOG_CLIENT_POKEMONBASICINFOWIDGET_HPP

# include "YAPOG/Macros.hpp"

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

    void Init (const Pokemon& pokemon);

    virtual bool IsFocusable () const;

  protected:
    virtual void HandleMove (const yap::Vector2& offset);
    virtual void HandleScale (const yap::Vector2& factor);
    virtual void HandleDraw (yap::IDrawingContext& offset);
    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);
    virtual void HandleUpdate (const yap::Time& dt);

  private:
    // Labels
    yap::Label* nameLeft_;
    yap::Label* nameRight_;
    yap::Label* staticID_;
    yap::Label* trainerName_;
    yap::Label* uniqueID_;
    yap::Label* item_;
    yap::Label* level_;
    yap::MultiLabelWidget* nature_;

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
    yap::HorizontalLayout* typesLayout_;

    yap::VerticalLayout* secondLine_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONBASICINFOWIDGET_HPP
