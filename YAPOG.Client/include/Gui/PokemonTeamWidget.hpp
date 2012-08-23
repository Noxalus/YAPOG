#ifndef YAPOG_CLIENT_POKEMONTEAMWIDGET_HPP
# define YAPOG_CLIENT_POKEMONTEAMWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/Graphics/Gui/PictureBox.hpp"
# include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
# include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
# include "YAPOG/Graphics/Gui/Label.hpp"
# include "YAPOG/System/StringHelper.hpp"
# include "YAPOG/Game/Pokemon/Gender.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/Graphics/Gui/GuiEvent.hpp"
# include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"
# include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"

# include "Pokemon/Pokemon.hpp"

namespace yap
{
  class GridMenu;
  class WidgetBackground;
}

namespace ycl
{
  class PokemonTeam;

  class PokemonTeamWidget : public yap::BaseWidget
  {

    DISALLOW_COPY(PokemonTeamWidget);

  public:
    PokemonTeamWidget (const PokemonTeam& team);
    void Init ();
    virtual ~PokemonTeamWidget();
    virtual bool IsFocusable () const;

  protected:
    virtual yap::Vector2 HandleGetSize () const;
    virtual void HandleMove (const yap::Vector2& offset);
    virtual void HandleScale (const yap::Vector2& factor);

    virtual void HandleDraw (yap::IDrawingContext& context);

    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    virtual void HandleUpdate (const yap::Time& dt);

    virtual bool HandleOnEvent (const yap::GuiEvent& guiEvent);
  private:

    class InfoBox : public yap::BaseWidget
    {
    public:
      InfoBox (bool isMainPok, const Pokemon& pokemon)
        : pokIcon_ (nullptr)
        , pokName_ (new yap::Label (pokemon.GetName ()))
        , pokLevel_ (
        new yap::Label (
        "N. " + yap::StringHelper::ToString (pokemon.GetLevel ())))
        , pokGender_ (nullptr)
        , HpBar_ (nullptr)
        , HpBarContent_ (nullptr)
        , hpLevel_ (new yap::Label (yap::StringHelper::ToString (pokemon.GetCurrentHP ()) + " / " + yap::StringHelper::ToString (pokemon.GetMaxHP ())))
        , vlayout_ (nullptr)
        , iSmainPok_ (isMainPok)
      {
        pokIcon_ = new yap::PictureBox ();
        pokGender_ = new yap::PictureBox ();
        HpBarContent_ = new yap::PictureBox ();
        HpBar_ = new yap::PictureBox ();

        pokIcon_->SetPicture (&pokemon.GetIcon ());
        pokGender_->SetPicture (&pokemon.GetGenderIcon ());

        // HP Bar
        HpBar_->SetPicture (
          new yap::Sprite ("Pictures/Battle/HPTeamManagerBar.png"));
        HpBarContent_->SetPicture (
          new yap::Sprite ("Pictures/Battle/HPBarContent.png"));

        HpBarContent_->SetSize (yap::Vector2 (130 * (pokemon.GetCurrentHP () / pokemon.GetMaxHP ()), HpBarContent_->GetSize ().y));
        HpBar_->AddChild (*HpBarContent_);
        HpBarContent_->Move (yap::Vector2 (45.f, 6.f));

        if (static_cast<float> (pokemon.GetCurrentHP ()) / static_cast<float> (pokemon.GetMaxHP ())  <= 0.25)
          HpBarContent_->ChangeColor (sf::Color (250, 90, 60));
        else if (static_cast<float> (pokemon.GetCurrentHP ()) / static_cast<float> (pokemon.GetMaxHP ())  <= 0.5)
          HpBarContent_->ChangeColor (sf::Color (250, 225, 50));
        else
          HpBarContent_->ChangeColor (sf::Color (110, 250, 170));

        if (isMainPok)
        {
          SetSize (yap::Vector2 (275, 172));
          SetBackground (*new yap::WidgetBackground ("Pictures/TeamManager/ItemBox.png", true));

          yap::HorizontalLayout* hor1 = new yap::HorizontalLayout (yap::Padding (), yap::Padding (), true);          
          hor1->SetDefaultColor (sf::Color::White);
          yap::HorizontalLayout* hor2 = new yap::HorizontalLayout (yap::Padding (), yap::Padding (), true);          
          hor2->SetDefaultColor (sf::Color::White);
          hor1->AddChild (*pokIcon_);
          hor1->AddChild (*pokName_);

          hor2->AddChild (*pokLevel_);
          hor2->AddChild (*pokGender_);

          vlayout_ = new yap::VerticalLayout (yap::Padding (), yap::Padding (), false);
          vlayout_->SetSize (GetSize ());
          vlayout_->SetDefaultColor (sf::Color::White);
          vlayout_->AddChild (*hor1);
          vlayout_->AddChild (*hor2);
          vlayout_->AddChild (*HpBar_);
          vlayout_->AddChild (*hpLevel_, yap::LayoutBox::Align::RIGHT);
          AddChild (*vlayout_);
        }
        else
        {
          SetSize (yap::Vector2 (425, 75));

          SetBackground (*new yap::WidgetBackground (
            "Pictures/TeamManager/ItemBox.png", true));

          yap::HorizontalLayout* hor1 = 
            new yap::HorizontalLayout (yap::Padding (), yap::Padding (), true);

          yap::VerticalLayout* ver1 = 
            new yap::VerticalLayout (yap::Padding (), yap::Padding (), true);
          yap::VerticalLayout* ver2 = 
            new yap::VerticalLayout (yap::Padding (), yap::Padding (), true);
          yap::VerticalLayout* ver3 = 
            new yap::VerticalLayout (yap::Padding (), yap::Padding (), true); 

          hor1->SetDefaultColor (sf::Color::White);

          ver1->SetDefaultColor (sf::Color::White);
          ver2->SetDefaultColor (sf::Color::White);
          ver3->SetDefaultColor (sf::Color::White);

          hor1->AddChild (*pokLevel_);
          hor1->AddChild (*pokGender_);

          ver1->AddChild (*pokIcon_);
          ver1->SetSize (yap::Vector2 (64, 64));

          ver2->AddChild (*pokName_);
          ver2->AddChild (*hor1);

          ver3->AddChild (*HpBar_);
          ver3->AddChild (*hpLevel_, yap::LayoutBox::Align::RIGHT);

          /*
          vlayout_ = new yap::VerticalLayout (yap::Padding (), yap::Padding (), false);
          vlayout_->SetSize (GetSize ());
          vlayout_->SetDefaultColor (sf::Color::White);
          vlayout_->AddChild (*ver1);
          vlayout_->AddChild (*ver2);
          vlayout_->AddChild (*ver3);
          */

          yap::HorizontalLayout* hlayout = 
            new yap::HorizontalLayout (yap::Padding (), yap::Padding (), false);
          hlayout->SetSize (GetSize ());
          hlayout->SetDefaultColor (sf::Color::White);
          hlayout->AddChild (*ver1);
          hlayout->AddChild (*ver2);
          hlayout->AddChild (*ver3);

          AddChild (*hlayout);
        }

      }
      virtual bool IsFocusable () const
      {
        return false;
      }

    private:
      yap::PictureBox* pokIcon_;
      yap::Label* pokName_;
      yap::Label* pokLevel_;
      yap::PictureBox* pokGender_;
      yap::PictureBox* HpBar_;
      yap::PictureBox* HpBarContent_;
      yap::Label* hpLevel_;
      yap::VerticalLayout* vlayout_;
      bool iSmainPok_;

    protected:
      virtual void HandleMove (const yap::Vector2& offset)
      {

      }
      virtual void HandleScale (const yap::Vector2& factor)
      {

      }
      virtual void HandleDraw (yap::IDrawingContext& offset)
      {

      }
      virtual void HandleShow (bool isVisible)
      {
      }
      virtual void HandleChangeColor (const sf::Color& color)
      {
      }
      virtual void HandleUpdate (const yap::Time& dt)
      {
      }
    };

    yap::Label* state_;
    Pokemon* current_;
    yap::GridMenu* menu_;
    yap::VerticalLayout* vlayoutMenu_;
    const PokemonTeam& team_;
    yap::collection::Array<InfoBox*> pokemons;
    InfoBox* currentBox_;
    yap::WidgetBackground* selecBckgrd_;
    yap::uint ite_;


  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONTEAMWIDGET_HPP