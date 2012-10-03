#include "YAPOG/Audio/AudioManager.hpp"
#include "YAPOG/Graphics/Gui/DialogBoxWidget.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Graphics/Gui/ProgressBarWidget.hpp"

#include "Battle/Phase/EndTurnPhase.hpp"
#include "Battle/Battle.hpp"
#include "Battle/BattleInterface.hpp"
#include "Battle/PokemonBattleInfoWidget.hpp"

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
      battleInterface_.GetPokemonInfoWidget ().
        GetExperienceBar ().OnProgressBarFinished.AddHandler (
        "ADD_EXPERIENCE_DISABLE_DIALOG_BOX",
        [&] (const yap::ProgressBarWidget& sender, 
        const yap::EmptyEventArgs& args)
      {
        battleInterface_.GetBattleInfoDialogBox ().SetEnable (true);
      });

      battleInterface_.GetPokemonInfoWidget ().
        GetExperienceBar ().OnExperienceBarLevelUp.AddHandler (
        "ADD_EXPERIENCE_LEVEL_UP", 
        [&] (const yap::ProgressBarWidget& sender, 
        const yap::EmptyEventArgs& args)
      {
        yap::AudioManager::Instance ().PlaySound ("SE/LevelUp.ogg");
      });

      battleInterface_.GetBattleInfoDialogBox ().Show (true);
      // We disable the dialog box to let the progress bar rise
      battleInterface_.GetBattleInfoDialogBox ().SetEnable (false);

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

    if (addExperience_)
    {
      battleInterface_.GetBattleInfoDialogBox ().OnTextChanged.RemoveHandler (
        "EXPERIENCE_TEXT_SKIPPED");

      battleInterface_.GetPokemonInfoWidget ().
        GetExperienceBar ().OnProgressBarFinished.RemoveHandler (
        "ADD_EXPERIENCE_DISABLE_DIALOG_BOX");

      battleInterface_.GetPokemonInfoWidget ().
        GetExperienceBar ().OnExperienceBarLevelUp.RemoveHandler (
        "ADD_EXPERIENCE_LEVEL_UP");
    }
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