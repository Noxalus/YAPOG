#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Game/Pokemon/Pokedex.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
#include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
#include "YAPOG/Graphics/Gui/Menu.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfo.hpp"

#include "Gui/PokedexCompositeWidget.hpp"

#include "Game.hpp"

namespace ycl
{

  PokedexCompositeWidget::PokedexCompositeWidget ()
    : menu_ (nullptr)
    , background_ (nullptr)
  {
 
  }

  PokedexCompositeWidget::~PokedexCompositeWidget ()
  {
  }

  void PokedexCompositeWidget::Init ()
  {
    background_ = new yap::WidgetBackground ("WindowSkins/BasicSkin/Pokedex/PokedexShfond1.png", true);
    //background_ = new yap::WidgetBackground ("WindowSkins/BasicSkin/Pokedex/PokemonBoxDefault.png", true);
    SetBackground (*background_);
  }

  bool PokedexCompositeWidget::IsFocusable () const
  {
    return true;
  }

  yap::Vector2 PokedexCompositeWidget::HandleGetSize () const
  {
    return yap::Vector2 (800, 600);
  }
  void PokedexCompositeWidget::HandleMove (const yap::Vector2& offset)
  {

  }
  void PokedexCompositeWidget::HandleScale (const yap::Vector2& factor)
  {

  }
  void PokedexCompositeWidget::HandleDraw (yap::IDrawingContext& context)
  {

  }
  void PokedexCompositeWidget::HandleShow (bool isVisible)
  {

  }
  void PokedexCompositeWidget::HandleChangeColor (const sf::Color& color)
  {

  }
  void PokedexCompositeWidget::HandleUpdate (const yap::Time& dt)
  {

  }
} // namespace ycl
