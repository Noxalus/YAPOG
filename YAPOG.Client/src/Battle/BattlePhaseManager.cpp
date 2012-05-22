#include "Battle/BattlePhaseManager.hpp"

namespace ycl
{
  BattlePhaseManager::BattlePhaseManager ()
  {
  }

  BattlePhaseManager::~BattlePhaseManager ()
  {
  }

  void BattlePhaseManager::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool BattlePhaseManager::IsVisible () const
  {
    return isVisible_;
  }

  void BattlePhaseManager::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void BattlePhaseManager::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  void BattlePhaseManager::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void BattlePhaseManager::HandleShow (bool isVisible)
  {
  }

  void BattlePhaseManager::HandleChangeColor (const sf::Color& color)
  {
  }
} // namespace ycl