#ifndef YAPOG_CLIENT_POKEMONTEAMWIDGET_HPP
# define YAPOG_CLIENT_POKEMONTEAMWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/Graphics/Gui/PictureBox.hpp"
# include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
# include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
# include "YAPOG/Graphics/Gui/Label.hpp"
# include "YAPOG/Game/Pokemon/Pokemon.hpp"
# include "YAPOG/System/StringHelper.hpp"
# include "YAPOG/Game/Pokemon/Gender.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/Graphics/Gui/GuiEvent.hpp"

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
      InfoBox (bool isMainPok, yap::Pokemon* info)
        : pokIcon_ (nullptr)
        , pokName_ (new yap::Label (info->GetName ()))
        , pokLevel_ (new yap::Label ("N. " + yap::StringHelper::ToString (info->GetLevel ())))
        , pokGender_ (nullptr)
        , HpBar_ (nullptr)
        , HpBarContent_ (nullptr)
        , hpLevel_ (new yap::Label (yap::StringHelper::ToString (info->GetCurrentHP ()) + " / " + yap::StringHelper::ToString (info->GetMaxHP ())))
        , vlayout_ (nullptr)
        , iSmainPok_ (isMainPok)
      {
        pokIcon_ = new yap::PictureBox ();
        pokGender_ = new yap::PictureBox ();
        HpBarContent_ = new yap::PictureBox ();
        HpBar_ = new yap::PictureBox ();

        pokIcon_->SetPicture (info->GetIcon ());
        if (info->GetGender () == yap::Gender::Female)
        {
          pokGender_->SetPicture ("Pictures/Battle/FemaleIcon.png");
        }
        else
        {
          pokGender_->SetPicture ("Pictures/Battle/MaleIcon.png");
        }
        HpBar_->SetPicture ("Pictures/Battle/HPTeamManagerBar.png");
        HpBarContent_->SetPicture ("Pictures/Battle/HPBarContent.png");
        HpBarContent_->SetSize (yap::Vector2 (130 * (info->GetCurrentHP () / info->GetMaxHP ()), HpBarContent_->GetSize ().y));
        HpBar_->AddChild (*HpBarContent_);
        HpBarContent_->Move (yap::Vector2 (45.f, 6.f));
        
        if (static_cast<float> (info->GetCurrentHP ()) / static_cast<float> (info->GetMaxHP ())  <= 0.25)
          HpBarContent_->ChangeColor (sf::Color (250, 90, 60));
        else if (static_cast<float> (info->GetCurrentHP ()) / static_cast<float> (info->GetMaxHP ())  <= 0.5)
          HpBarContent_->ChangeColor (sf::Color (250, 225, 50));
        else
          HpBarContent_->ChangeColor (sf::Color (110, 250, 170));
        if (isMainPok)
        {
          SetSize (yap::Vector2 (275, 172));
          SetBackground (*new yap::WidgetBackground ("Pictures/TeamManager/ItemB.png", true));

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
    yap::Pokemon* current_;
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