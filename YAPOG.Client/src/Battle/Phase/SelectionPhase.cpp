#include "YAPOG/Graphics/Gui/DialogBoxWidget.hpp"
#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"
#include "YAPOG/System/StringHelper.hpp"

#include "Battle/Phase/SelectionPhase.hpp"
#include "Battle/Battle.hpp"
#include "Battle/BattleInterface.hpp"

namespace ycl
{
  const bool SelectionPhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color SelectionPhase::DEFAULT_COLOR = sf::Color ();

  SelectionPhase::SelectionPhase (
    Battle& battle, 
    BattleInterface& battleInterface)
    : yap::SelectionPhase (battle)
    , battle_ (battle)
    , battleInterface_  (battleInterface)
    , runFlag_ (false)
    , actionFlag_ (false)
  {
  }

  SelectionPhase::~SelectionPhase ()
  {
  }

  void SelectionPhase::Init ()
  {
    battleInterface_.GetBattleMenu ().GetItem (2).OnActivated +=
      [&] (const yap::MenuItem& sender, const yap::EmptyEventArgs& args)
    {
      battleInterface_.SetCurrentWidget ("PokemonTeam");
    };

    battleInterface_.GetBattleMenu ().GetItem (3).OnActivated +=
      [&] (const yap::MenuItem& sender, const yap::EmptyEventArgs& args)
    {
      runFlag_ = true;
    };
  }

  void SelectionPhase::HandleStart (const yap::PhaseArgs& args)
  {
    yap::SelectionPhase::HandleStart (args);

    battleInterface_.GetBattleInfoDialogBox ().AddText (
      "Que doit faire\n\n" +
      battle_.GetPlayerTeam ().GetName () + " ?");

    battleInterface_.GetBattleInfoDialogBox ().Show (true);
    battleInterface_.GetBattleInfoDialogBox ().SetEnable (false);

    battleInterface_.GetBattleMenu ().Open ();

    // BattleMoveMenu events
    for (yap::uint i = 0; 
      i < battle_.GetPlayerTeam ().GetMoveSet ().GetMoveNumber (); 
      i++)
    {
      battleInterface_.GetBattleMoveMenu ().GetItem (i).OnActivated.
        AddHandler ("BattleMoveMenuItem" + yap::StringHelper::ToString (i),
        [this, i] (yap::MenuItem& sender, const yap::EmptyEventArgs& args)
      {
        actionFlag_ = true;
        phaseArgs_.choice_ = yap::BattleChoice::Move;
        phaseArgs_.index_ = i;
        battleInterface_.CloseBattleMoveMenu ();
      });
    }

    // Reset flags
    runFlag_ = false;
    actionFlag_ = false;
  }

  void SelectionPhase::HandleUpdate (const yap::Time& dt)
  {
    yap::SelectionPhase::HandleUpdate (dt);

    if (runFlag_)
    {
      yap::BattlePhase::SwitchPhase (yap::BattlePhaseState::Run);
    }
    else if (actionFlag_)
    {
      yap::BattlePhase::SwitchPhase (
        yap::BattlePhaseState::BeginTurn,
        phaseArgs_);
    }
  }

  void SelectionPhase::HandleEnd ()
  {
    yap::SelectionPhase::HandleEnd ();

    battleInterface_.GetBattleInfoDialogBox ().SkipText ();

    for (yap::uint i = 0; 
      i < battle_.GetPlayerTeam ().GetMoveSet ().GetMoveNumber (); 
      i++)
    {
        battleInterface_.GetBattleMoveMenu ().GetItem (i).OnActivated.
          RemoveHandler (
          "BattleMoveMenuItem" + yap::StringHelper::ToString (i));
    }
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