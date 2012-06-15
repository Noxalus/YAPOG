#ifndef YAPOG_CLIENT_POKEMONTEAMWIDGET_HPP
# define YAPOG_CLIENT_POKEMONTEAMWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/Graphics/Gui/PictureBox.hpp"
# include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
# include "YAPOG/Graphics/Gui/Label.hpp"
# include "YAPOG/Game/Pokemon/Pokemon.hpp"
# include "YAPOG/System/StringHelper.hpp"
# include "YAPOG/Game/Pokemon/Gender.hpp"

namespace yap
{
  class Menu;
}

namespace ycl
{
  class PokemonTeamWidget : public yap::BaseWidget
  {

    DISALLOW_COPY(PokemonTeamWidget);

  public:


    PokemonTeamWidget ();
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

  private:

    class InfoBox : public yap::BaseWidget
    {
    public:
      InfoBox (bool isMainPok, yap::Pokemon* info)
        : pokIcon_ ()
        , pokName_ (info->GetName ())
        , pokLevel_ ("N. " + yap::StringHelper::ToString (info->GetLevel ()))
        , pokGender_ ()
        , HpBar_ ()
        , HpBarContent_ ()
        , hpLevel_ (yap::StringHelper::ToString (info->GetCurrentHP ()) + " / " + yap::StringHelper::ToString (info->GetMaxHP ()))
        , iSmainPok_ (isMainPok)
      {
        pokIcon_.SetPicture (info->GetIcon ());
        if (info->GetGender () == yap::Gender::Female)
        {
          pokGender_.SetPicture ("Pictures/Battle/FemaleIcon.png");
        }
        else
        {
          pokGender_.SetPicture ("Pictures/Battle/MaleIcon.png");
        }
        HpBar_.SetPicture ("Pictures/Battle/HPTeamManagerBar.png");
        HpBarContent_.SetPicture ("Pictures/Battle/HPBarContent.png");
        HpBarContent_.SetSize (yap::Vector2 (172, HpBarContent_.GetSize ().y));
        
        if (isMainPok)
        {
          SetSize (yap::Vector2 (230, 166));
          SetBackground (*new yap::WidgetBackground ("Pictures/TeamManager/ItemBackground.png", true));
          pokIcon_.SetPosition (GetPosition () + yap::Vector2 (10, 10));
          pokName_.SetPosition (GetPosition () + yap::Vector2 (10 + pokIcon_.GetSize ().x, 10));
        }
      }

    private:
      yap::PictureBox pokIcon_;
      yap::Label pokName_;
      yap::Label pokLevel_;
      yap::PictureBox pokGender_;
      yap::PictureBox HpBar_;
      yap::PictureBox HpBarContent_;
      yap::Label hpLevel_;
      bool iSmainPok_;

    protected:
      virtual void HandleMove (const yap::Vector2& offset)
      {
        pokIcon_.Move (offset);
        pokName_.Move (offset);
        pokLevel_.Move (offset);
        pokGender_.Move (offset);
        HpBar_.Move (offset);
        HpBarContent_.Move (offset);
        hpLevel_.Move (offset);
      }
      virtual void HandleScale (const yap::Vector2& factor)
    {
        pokIcon_.Scale (factor);
        pokName_.Scale (factor);
        pokLevel_.Scale (factor);
        pokGender_.Scale (factor);
        HpBar_.Scale (factor);
        HpBarContent_.Scale (factor);
        hpLevel_.Scale (factor);
      }
      virtual void HandleDraw (yap::IDrawingContext& offset)
      {
        pokIcon_.Draw (offset);
        pokName_.Draw (offset);
        pokLevel_.Draw (offset);
        pokGender_.Draw (offset);
        HpBar_.Draw (offset);
        HpBarContent_.Draw (offset);
        hpLevel_.Draw (offset);
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
    yap::Menu* menu_;
    yap::VerticalLayout* vlayoutMenu_;


  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONTEAMWIDGET_HPP