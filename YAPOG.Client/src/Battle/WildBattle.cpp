#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Graphics/Texture.hpp"
#include "Battle/WildBattle.hpp"
#include "Battle/Phase/BeginBattlePhase.hpp"
#include "TestGame.hpp"

namespace ycl
{
  const yap::Vector2 WildBattle::DEFAULT_GROUND_SPRITES_SCALE = 
    yap::Vector2 (1.f, 1.f);

  WildBattle::WildBattle (
    yap::IBattleEntity& playerTeam, 
    yap::IBattleEntity& wildPokemon)
    : yap::WildBattle (playerTeam, wildPokemon)
  {
  }

  WildBattle::~WildBattle ()
  {
  }

  void WildBattle::HandleInit ()
  {
    Battle::HandleInit ();

    background_ = new yap::Sprite (yap::ObjectFactory::Instance ().
      Create<yap::Texture> ("Texture", yap::ID (42)));
    opponentGround_ = new yap::Sprite (yap::ObjectFactory::Instance ().
      Create<yap::Texture> ("Texture", yap::ID (43)));
    playerGround_ = new yap::Sprite (yap::ObjectFactory::Instance ().
      Create<yap::Texture> ("Texture", yap::ID (43)));

    background_->SetSize (TestGame::SCREEN_SIZE);

    playerGround_->Scale (DEFAULT_GROUND_SPRITES_SCALE);
    playerGround_->SetPosition (
      yap::Vector2 (0, 
      TestGame::SCREEN_SIZE.y - (TestGame::SCREEN_SIZE.y / 4) -
      ((playerGround_->GetSize ().y * DEFAULT_GROUND_SPRITES_SCALE.y) / 2)));

    opponentGround_->Scale (DEFAULT_GROUND_SPRITES_SCALE);
    opponentGround_->SetPosition (
      yap::Vector2 (
      TestGame::SCREEN_SIZE.x - 2 *
      ((playerGround_->GetSize ().x * DEFAULT_GROUND_SPRITES_SCALE.x) / 2), 
      TestGame::SCREEN_SIZE.y / 3 - 
      ((playerGround_->GetSize ().y * 
      DEFAULT_GROUND_SPRITES_SCALE.y) / 2)));

    BeginBattlePhase* beginBattlePhase = new BeginBattlePhase ();

    AddPhase (yap::BattlePhaseState::BeginBattle, beginBattlePhase);
  }

  void WildBattle::HandleUpdate (const yap::Time& dt)
  {
    Battle::HandleUpdate (dt);
  }

  void WildBattle::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool WildBattle::IsVisible () const
  {
    return isVisible_;
  }

  void WildBattle::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void WildBattle::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  void WildBattle::HandleDraw (yap::IDrawingContext& context)
  {
    background_->Draw (context);
    playerGround_->Draw (context);
    opponentGround_->Draw (context);
  }

  void WildBattle::HandleShow (bool isVisible)
  {
  }

  void WildBattle::HandleChangeColor (const sf::Color& color)
  {
  }

} // namespace yap