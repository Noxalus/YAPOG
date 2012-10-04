#include "YAPOG/Audio/AudioManager.hpp"
#include "YAPOG/Graphics/Gui/DialogBoxWidget.hpp"
#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

#include "Battle/Phase/EndWildBattlePhase.hpp"
#include "Battle/Battle.hpp"
#include "Battle/BattleInterface.hpp"

namespace ycl
{
  const bool EndWildBattlePhase::DEFAULT_VISIBLE_STATE = true;
  const sf::Color EndWildBattlePhase::DEFAULT_COLOR = sf::Color ();

  EndWildBattlePhase::EndWildBattlePhase (
    Battle& battle, 
    BattleInterface& battleInterface)
    : EndBattlePhase (battle, battleInterface)
  {
  }

  EndWildBattlePhase::~EndWildBattlePhase ()
  {
  }

  void EndWildBattlePhase::HandleStart (const yap::PhaseArgs& args)
  {
     ycl::EndBattlePhase::HandleStart (args);

     battleInterface_.GetBattleInfoDialogBox ().Show (true);
     battleInterface_.GetBattleInfoDialogBox ().SetEnable (true);

     battleInterface_.GetBattleInfoDialogBox ().
       AddText ("Vous avez remporté le combat contre le Pokémon sauvage !");

     yap::AudioManager::Instance ().PlayMusic ("SE/WildBattleVictory.ogg");
  }

  void EndWildBattlePhase::HandleUpdate (const yap::Time& dt)
  {
    ycl::EndBattlePhase::HandleUpdate (dt);
  }

  void EndWildBattlePhase::HandleEnd ()
  {
    ycl::EndBattlePhase::HandleEnd ();
  }

  void EndWildBattlePhase::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void EndWildBattlePhase::HandleShow (bool isVisible)
  {
  }

  void EndWildBattlePhase::HandleChangeColor (const sf::Color& color)
  {
  }
}