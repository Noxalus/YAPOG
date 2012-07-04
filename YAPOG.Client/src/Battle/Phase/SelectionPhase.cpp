#include "YAPOG/Graphics/Gui/DialogBoxWidget.hpp"
#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

#include "Battle/Phase/SelectionPhase.hpp"
#include "Battle/Battle.hpp"
#include "Battle/BattleInterface.hpp"

namespace ycl
{
  const bool SelectionPhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color SelectionPhase::DEFAULT_COLOR = sf::Color ();

  SelectionPhase::SelectionPhase (Battle& battle, BattleInterface& battleInterface)
    : yap::SelectionPhase (battle)
    , battle_ (battle)
    , battleInterface_  (battleInterface)
    , runFlag_ (false)
  {
  }

  SelectionPhase::~SelectionPhase ()
  {
  }

  void SelectionPhase::Init ()
  {
    battleInterface_.GetBattleMenu ().GetItem (3).OnActivated +=
      [&] (const yap::MenuItem& sender, const yap::EmptyEventArgs& args)
    {
      runFlag_ = true;
    };
  }

  void SelectionPhase::HandleStart (yap::PhaseArgs* args)
  {
    yap::SelectionPhase::HandleStart (args);

    battleInterface_.GetBattleInfoDialogBox ().AddText (
      "Que doit faire\n\n" +
      battle_.GetPlayerTeam ().GetName () + " ?");

    battleInterface_.GetBattleInfoDialogBox ().Show (true);
    battleInterface_.GetBattleInfoDialogBox ().SetEnable (false);

    battleInterface_.GetBattleMenu ().Open ();
  }

  void SelectionPhase::HandleUpdate (const yap::Time& dt)
  {
    yap::SelectionPhase::HandleUpdate (dt);

    if (runFlag_)
    {
      battleInterface_.GetBattleInfoDialogBox ().SkipText ();
      yap::BattlePhase::SwitchPhase (yap::BattlePhaseState::Run);
    }
  }

  void SelectionPhase::HandleEnd ()
  {
    yap::SelectionPhase::HandleEnd ();
  }

  void SelectionPhase::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool SelectionPhase::IsVisible () const
  {
    return isVisible_;
  }

  void SelectionPhase::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void SelectionPhase::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  void SelectionPhase::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void SelectionPhase::HandleShow (bool isVisible)
  {
  }

  void SelectionPhase::HandleChangeColor (const sf::Color& color)
  {
  }
}