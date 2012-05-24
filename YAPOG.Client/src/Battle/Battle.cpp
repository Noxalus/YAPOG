#include "YAPOG/Game/Battle/IBattleEntity.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"

#include "TestGame.hpp"
#include "Battle/Battle.hpp"

namespace ycl
{
  const bool Battle::DEFAULT_VISIBLE_STATE = true;
  const sf::Color Battle::DEFAULT_COLOR = sf::Color ();
  const yap::Vector2 Battle::DEFAULT_OPPONENT_GROUND_SPRITES_SCALE
    = yap::Vector2 (0.75f, 0.75f);


  Battle::Battle (
    yap::IBattleEntity& playerTeam, 
    yap::IBattleEntity& opponent)
    : yap::Battle (playerTeam, opponent)
    , isVisible_ (DEFAULT_VISIBLE_STATE)
    , color_ (DEFAULT_COLOR)
    , background_ (nullptr)
    , playerGround_ (nullptr)
    , opponentGround_ (nullptr)
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

    /// Adjust sprites
    background_->SetSize (TestGame::SCREEN_SIZE);

    playerGround_->SetPosition (
      yap::Vector2 (0, 
      TestGame::SCREEN_SIZE.y - (TestGame::SCREEN_SIZE.y / 4) -
      ((playerGround_->GetSize ().y) / 2)));

    opponentGround_->Scale (DEFAULT_OPPONENT_GROUND_SPRITES_SCALE);
    opponentGround_->SetPosition (
      yap::Vector2 (
      TestGame::SCREEN_SIZE.x - 2 *
      ((playerGround_->GetSize ().x * 
      DEFAULT_OPPONENT_GROUND_SPRITES_SCALE.x) / 2), 
      TestGame::SCREEN_SIZE.y / 3 - 
      ((playerGround_->GetSize ().y * 
      DEFAULT_OPPONENT_GROUND_SPRITES_SCALE.y) / 2)));
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
    opponentGround_->Update (dt);
  }

  void Battle::HandleDraw (yap::IDrawingContext& context)
  {
    background_->Draw (context);
    playerGround_->Draw (context);
    opponentGround_->Draw (context);
  }

  void Battle::HandleShow (bool isVisible)
  {
  }

  void Battle::HandleChangeColor (const sf::Color& color)
  {
  }

} // namespace yap