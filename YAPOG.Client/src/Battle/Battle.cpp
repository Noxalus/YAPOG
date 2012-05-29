#include "YAPOG/Game/Battle/IBattleEntity.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"

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

  Battle::Battle ()
    : yap::Battle ()
    , isVisible_ (DEFAULT_VISIBLE_STATE)
    , color_ (DEFAULT_COLOR)
    , background_ (nullptr)
    , playerGround_ (nullptr)
    , opponentGround_ (nullptr)
    , playerTrainerBack_ (nullptr)
    , playerTeam_ (nullptr)
    , opponent_ (nullptr)
  {
  }

  Battle::~Battle ()
  {
    delete background_;
    delete playerGround_;
    delete opponentGround_;
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

  const yap::Vector2& Battle::GetPlayerGroundPosition () const
  { return playerGroundPosition_; }

  const yap::Vector2& Battle::GetOpponentGroundPosition () const
  { return opponentGroundPosition_; }

  const IDrawableBattleEntity& Battle::GetDrawablePlayerTeam () const
  { return *playerTeam_; }

  IDrawableBattleEntity& Battle::GetDrawablePlayerTeam ()
  { return *playerTeam_; }

  const IDrawableBattleEntity& Battle::GetDrawableOpponent () const
  { return *opponent_; }

  IDrawableBattleEntity& Battle::GetDrawableOpponent ()
  { return *opponent_; }

  /// Setters
  void Battle::SetPlayerGroundPosition (const yap::Vector2& position)
  {
    playerGroundPosition_ = position;
  }

  void Battle::SetOpponentGroundPosition (const yap::Vector2& position)
  {
    opponentGroundPosition_ = position;
  }

  void Battle::SetDrawablePlayerTeam (PokemonFighterTeam* playerTeam)
  {
    yap::Battle::SetPlayerTeam (playerTeam);
    playerTeam_ = playerTeam;
  }

  void Battle::SetDrawableOpponent (PokemonFighterTeam* opponent)
  {
    yap::Battle::SetOpponent (opponent);
    opponent_ = opponent;
  }

  void Battle::SetDrawableOpponent (PokemonFighter* opponent)
  {
    yap::Battle::SetOpponent (opponent);
    opponent_ = opponent;
  }

  void Battle::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;
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
    /*
    playerTeam_->Draw (context);
    opponent_->Draw (context);
    */
  }

  void Battle::HandleShow (bool isVisible)
  {
  }

  void Battle::HandleChangeColor (const sf::Color& color)
  {
  }

} // namespace yap
