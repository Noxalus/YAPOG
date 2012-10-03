#include "YAPOG/Game/Battle/IBattleEntity.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Game/Battle/Phase/BattlePhaseManager.hpp"

#include "Battle/BattleInterface.hpp"
#include "Battle/OpponentBattleInfoWidget.hpp"
#include "Battle/PokemonBattleInfoWidget.hpp"
#include "Battle/IDrawableBattleEntity.hpp"
#include "Battle/PokemonFighter.hpp"
#include "Battle/PokemonFighterTeam.hpp"
#include "Game.hpp"
#include "Battle/Battle.hpp"

namespace ycl
{
  const bool Battle::DEFAULT_VISIBLE_STATE = true;
  const sf::Color Battle::DEFAULT_COLOR = sf::Color ();
  const yap::Vector2 Battle::DEFAULT_OPPONENT_GROUND_SPRITES_SCALE
    = yap::Vector2 (0.75f, 0.75f);

  // Positions
  const yap::Vector2 Battle::OPPONENT_POSITION (578, 82);
  const yap::Vector2 Battle::OPPONENT_INFO_POSITION (216, 36);
  const yap::Vector2 Battle::OPPONENT_GROUND_POSITION (517, 162);
  const yap::Vector2 Battle::PLAYER_POSITION (117, 301);
  const yap::Vector2 Battle::POKEMON_POSITION;
  const yap::Vector2 Battle::POKEMON_INFO_POSITION;
  const yap::Vector2 Battle::POKEMON_GROUND_POSITION (0, 400);

  Battle::Battle (BattleInterface& battleInterface)
    : yap::Battle ()
    , isVisible_ (DEFAULT_VISIBLE_STATE)
    , color_ (DEFAULT_COLOR)
    , battleInterface_ (battleInterface)
    , background_ (nullptr)
    , playerGround_ (nullptr)
    , opponentGround_ (nullptr)
    , playerTrainerBack_ (nullptr)
    , playerGroundPosition_ ()
    , opponentGroundPosition_ ()
    , opponentInfoPosition_ ()
    , pokemonInfoPosition_ ()
    , playerTeam_ (nullptr)
    , opponent_ (nullptr)
  {
  }

  Battle::~Battle ()
  {
    delete background_;
    delete playerGround_;
    delete opponentGround_;
    delete playerTrainerBack_;
  }

  void Battle::HandleInit ()
  {
    /// Load sprites
    background_ = new yap::Sprite (yap::ObjectFactory::Instance ().
      Create<yap::Texture> ("Texture", yap::ID (42)));

    opponentGround_ = new yap::Sprite (yap::ObjectFactory::Instance ().
      Create<yap::Texture> ("Texture", yap::ID (43)));

    playerGround_ = new yap::Sprite (yap::ObjectFactory::Instance ().
      Create<yap::Texture> ("Texture", yap::ID (43)));

    playerTrainerBack_ = new yap::Sprite (yap::ObjectFactory::Instance ().
      Create<yap::Texture> ("Texture", yap::ID (44)));

    /// Adjust sprites
    background_->SetSize (Game::SCREEN_SIZE);
    opponentGround_->Scale (DEFAULT_OPPONENT_GROUND_SPRITES_SCALE);

    playerGroundPosition_ = yap::Vector2 (0,
      Game::SCREEN_SIZE.y - (Game::SCREEN_SIZE.y / 4) -
      ((playerGround_->GetSize ().y) / 2));

    opponentGroundPosition_ = yap::Vector2 (
      Game::SCREEN_SIZE.x -
      (opponentGround_->GetSize ().x),
      Game::SCREEN_SIZE.y / 3 -
      (opponentGround_->GetSize ().y) / 2);

    opponentInfoPosition_ = yap::Vector2 (
      opponentGroundPosition_.x - 
      battleInterface_.GetOpponentInfoWidget ().GetSize ().x,
      opponentGroundPosition_.y - 
      1.5f * battleInterface_.GetOpponentInfoWidget ().GetSize ().y);

    pokemonInfoPosition_ = yap::Vector2 (
      playerGroundPosition_.x + 
      playerGround_->GetSize ().x,
      playerGroundPosition_.y - 
      battleInterface_.GetPokemonInfoWidget ().GetSize ().y);

    // Hide some sprites
    playerTeam_->Show (false);
  }

  /// Getters
  yap::ISprite& Battle::GetBackground () const
  { return *background_; }

  yap::ISprite& Battle::GetPlayerGround () const
  { return *playerGround_; }

  yap::ISprite& Battle::GetOpponentGround () const
  { return *opponentGround_; }

  yap::ISprite& Battle::GetPlayerTrainerBack () const
  { return *playerTrainerBack_; }

  yap::ISprite& Battle::GetPlayerTeamSprite ()
  { return playerTeam_->GetBattleSprite (); }

  yap::ISprite& Battle::GetOpponentSprite ()
  { return opponent_->GetBattleSprite (); }

  const yap::Vector2& Battle::GetPlayerGroundPosition () const
  { return playerGroundPosition_; }

  const yap::Vector2& Battle::GetOpponentGroundPosition () const
  { return opponentGroundPosition_; }

  const yap::Vector2& Battle::GetOpponentInfoPosition () const
  { return opponentInfoPosition_; }

  const yap::Vector2& Battle::GetPokemonInfoPosition () const
  { return pokemonInfoPosition_; }

  IDrawableBattleEntity& Battle::GetPlayerTeam ()
  { return *playerTeam_; }

  IDrawableBattleEntity& Battle::GetOpponent ()
  { return *opponent_; }

  /// Setters
  void Battle::SetPlayerTeam (PokemonFighterTeam* playerTeam)
  { playerTeam_ = playerTeam; }

  void Battle::SetOpponent (IDrawableBattleEntity* opponent)
  { opponent_ = opponent; }

  void Battle::SetPlayerTeamPosition (const yap::Vector2& value)
  { playerTeam_->SetPosition (value); }

  void Battle::SetOpponentPosition (const yap::Vector2& value)
  { opponent_->SetPosition (value); }

  void Battle::ShowPlayerTeam (bool isVisible)
  { playerTeam_->Show (isVisible); }

  void Battle::ShowOpponent (bool isVisible)
  { opponent_->Show (isVisible); }

  void Battle::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool Battle::IsVisible () const
  {
    return isVisible_;
  }

  void Battle::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void Battle::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  void Battle::HandleUpdate (const yap::Time& dt)
  {
    background_->Update (dt);
    playerGround_->Update (dt);
    playerTrainerBack_->Update (dt);
    opponentGround_->Update (dt);
  }

  void Battle::HandleDraw (yap::IDrawingContext& context)
  {
    background_->Draw (context);
    playerGround_->Draw (context);
    playerTrainerBack_->Draw (context);
    opponentGround_->Draw (context);
    GetPlayerTeam ().Draw (context);
    GetOpponent ().Draw (context);
  }

  void Battle::HandleShow (bool isVisible)
  {
  }

  void Battle::HandleChangeColor (const sf::Color& color)
  {
  }

} // namespace ycl
