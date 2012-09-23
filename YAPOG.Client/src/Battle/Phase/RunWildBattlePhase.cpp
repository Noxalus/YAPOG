#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"
#include "YAPOG/Graphics/Gui/DialogBoxWidget.hpp"

#include "Battle/Phase/RunWildBattlePhase.hpp"
#include "Battle/Battle.hpp"
#include "Battle/BattleInterface.hpp"

namespace ycl
{
  const bool RunWildBattlePhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color RunWildBattlePhase::DEFAULT_COLOR = sf::Color ();

  RunWildBattlePhase::RunWildBattlePhase (Battle& battle, BattleInterface& battleInterface)
    : yap::RunWildBattlePhase (battle)
    , battle_ (battle)
    , battleInterface_ (battleInterface)
    , flagEndBattle_ (false)
  {
  }

  RunWildBattlePhase::~RunWildBattlePhase ()
  {
  }

  void RunWildBattlePhase::Init ()
  {
  }

  void RunWildBattlePhase::HandleStart (const yap::PhaseArgs& args)
  {
    yap::RunWildBattlePhase::HandleStart (args);

    battleInterface_.GetBattleMenu ().Close ();
    battleInterface_.GetBattleInfoDialogBox ().SetEnable (true);
    battleInterface_.GetBattleInfoDialogBox ().AddText (
      "Vous prenez la fuite !");

    battleInterface_.GetBattleInfoDialogBox ().Show (true);
    battleInterface_.GetBattleInfoDialogBox ().SetEnable (true);

    battleInterface_.GetBattleInfoDialogBox ().OnTextChanged.AddHandler (
      "SKIP_RUN_TEXT_EVENT_HANDLER",
      [&] (const yap::BaseWidget& sender, const yap::EmptyEventArgs& args)
    {
      battleInterface_.GetBattleInfoDialogBox ().
        OnTextChanged.RemoveHandler ("SKIP_RUN_TEXT_EVENT_HANDLER");

      flagEndBattle_ = true;
    });
  }

  void RunWildBattlePhase::HandleUpdate (const yap::Time& dt)
  {
    /// @todo Change to yap::RunBattlePhase
    yap::RunWildBattlePhase::HandleUpdate (dt);

    if (flagEndBattle_)
      BattlePhase::SwitchPhase (yap::BattlePhaseState::EndBattle);
  }

  void RunWildBattlePhase::HandleEnd ()
  {
    yap::RunWildBattlePhase::HandleEnd ();
  }

  void RunWildBattlePhase::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool RunWildBattlePhase::IsVisible () const
  {
    return isVisible_;
  }

  void RunWildBattlePhase::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void RunWildBattlePhase::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  void RunWildBattlePhase::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void RunWildBattlePhase::HandleShow (bool isVisible)
  {
  }

  void RunWildBattlePhase::HandleChangeColor (const sf::Color& color)
  {
  }
}