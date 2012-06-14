#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
#include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
#include "YAPOG/Graphics/Gui/Menu.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/System/StringHelper.hpp"

#include "Gui/PokemonTeamWidget.hpp"

#include "Game.hpp"

namespace ycl
{

  PokemonTeamWidget::PokemonTeamWidget ()
   
  {
 
  }

  PokemonTeamWidget::~PokemonTeamWidget ()
  {
  }

  void PokemonTeamWidget::Init ()
  {
  
  }

  bool PokemonTeamWidget::IsFocusable () const
  {
    return true;
  }

  yap::Vector2 PokemonTeamWidget::HandleGetSize () const
  {
    return yap::Vector2 (800, 600);
  }
  void PokemonTeamWidget::HandleMove (const yap::Vector2& offset)
  {

  }
  void PokemonTeamWidget::HandleScale (const yap::Vector2& factor)
  {

  }
  void PokemonTeamWidget::HandleDraw (yap::IDrawingContext& context)
  {

  }
  void PokemonTeamWidget::HandleShow (bool isVisible)
  {

  }
  void PokemonTeamWidget::HandleChangeColor (const sf::Color& color)
  {

  }
  void PokemonTeamWidget::HandleUpdate (const yap::Time& dt)
  {

  }
} // namespace ycl
