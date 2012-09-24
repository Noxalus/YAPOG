#include "YAPOG/Graphics/Gui/DialogBoxWidget.hpp"
#include "YAPOG/System/StringHelper.hpp"

#include "Battle/Phase/EndTurnPhase.hpp"
#include "Battle/Battle.hpp"
#include "Battle/BattleInterface.hpp"

namespace ycl
{
  const bool EndTurnPhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color EndTurnPhase::DEFAULT_COLOR = sf::Color ();

  EndTurnPhase::EndTurnPhase (
    Battle& battle, 
    BattleInterface& battleInterface)
    : yap::EndTurnPhase (battle)
    , battle_ (battle)
    , battleInterface_  (battleInterface)
  {
  }

  EndTurnPhase::~EndTurnPhase ()
  {
  }

  void EndTurnPhase::HandleStart (const yap::PhaseArgs& args)
  {
    yap::EndTurnPhase::HandleStart (args);

    // Add message in dialog box to notice the experience amount earned
    if (addExperience_)
    {
      battleInterface_.GetBattleInfoDialogBox ().Show (true);
      battleInterface_.GetBattleInfoDialogBox ().SetEnable (true);

      battleInterface_.GetBattleInfoDialogBox ().AddText (
        battle_.GetPlayerTeam ().GetName () + " gagne "
        + yap::StringHelper::ToString (experienceAmount_) +
        " point(s) d'expérience !");

      battleInterface_.GetBattleInfoDialogBox ().OnTextChanged.AddHandler (
        "EXPERIENCE_TEXT_SKIPPED",
        [&] (const yap::BaseWidget& sender, const yap::EmptyEventArgs& args)
      {
        textSkipped_ = true;
      });
    }
  }

  void EndTurnPhase::HandleUpdate (const yap::Time& dt)
  {
    yap::EndTurnPhase::HandleUpdate (dt);
  }

  void EndTurnPhase::HandleEnd ()
  {
    yap::EndTurnPhase::HandleEnd ();
  }

  void EndTurnPhase::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool EndTurnPhase::IsVisible () const
  {
    return isVisible_;
  }

  void EndTurnPhase::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void EndTurnPhase::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  void EndTurnPhase::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void EndTurnPhase::HandleShow (bool isVisible)
  {
  }

  void EndTurnPhase::HandleChangeColor (const sf::Color& color)
  {
  }
}