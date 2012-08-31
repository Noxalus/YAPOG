#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
#include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/System/StringHelper.hpp"

#include "Client/User.hpp"
#include "Gui/TrainerCardWidget.hpp"

namespace ycl
{
  TrainerCardWidget::TrainerCardWidget (const User& user)
    : user_ (user)
    , uniqueIDLabel_ (nullptr)
    , uniqueID_ (nullptr)
    , nameLabel_ (nullptr)
    , name_ (nullptr)
    , moneyLabel_ (nullptr)
    , money_ (nullptr)
    , pokedexLabel_ (nullptr)
    , pokedex_ (nullptr)
    , gameTimeLabel_ (nullptr)
    , gameTime_ (nullptr)
    , playerSprite_ (nullptr)
    , mainLayout_ (nullptr)
    , firstLine_ (nullptr)
    , uniqueIDLayout_ (nullptr)
    , secondLine_ (nullptr)
    , secondLinePartLeft_ (nullptr)
    , nameLayout_ (nullptr)
    , playerDataLayout_ (nullptr)
    , playerDataLabelsLayout_ (nullptr)
    , playerDataValuesLayout_ (nullptr)
    , secondLinePartRight_ (nullptr)
    , playerSpriteLayout_ (nullptr)
  {
    // Labels
    uniqueIDLabel_ = new yap::Label ("ID");
    uniqueID_ = new yap::Label ();
    nameLabel_ = new yap::Label ("Nom:");
    name_ = new yap::Label ();
    moneyLabel_ = new yap::Label ("Argent:");
    money_ = new yap::Label ();
    pokedexLabel_ = new yap::Label ("Pokédex:");
    pokedex_ = new yap::Label ();
    gameTimeLabel_ = new yap::Label ("Durée de jeu:");
    gameTime_ = new yap::Label ();

    // PïctureBoxes
    playerSprite_ = new yap::PictureBox ();

    // Layouts
    mainLayout_ = new yap::VerticalLayout (
      yap::Padding (), yap::Padding (), false);

    firstLine_ = new yap::VerticalLayout (
      yap::Padding (0, 0, 21, 0), yap::Padding (), false);

    uniqueIDLayout_ = new yap::HorizontalLayout (
      yap::Padding (), yap::Padding (), false);

    secondLine_ = new yap::HorizontalLayout (
      yap::Padding (), yap::Padding (), false);

    secondLinePartLeft_ = new yap::VerticalLayout (
      yap::Padding (), yap::Padding (), false);

    nameLayout_ = new yap::VerticalLayout (
      yap::Padding (), yap::Padding (), false);
    playerDataLayout_ = new yap::HorizontalLayout (
      yap::Padding (), yap::Padding (), false);
    playerDataLabelsLayout_ = new yap::VerticalLayout (
      yap::Padding (), yap::Padding (), false);
    playerDataValuesLayout_ = new yap::VerticalLayout (
      yap::Padding (), yap::Padding (), false);

    secondLinePartRight_ = new yap::VerticalLayout (
      yap::Padding (), yap::Padding (), false);

    playerSpriteLayout_ = new yap::HorizontalLayout (
      yap::Padding (), yap::Padding (), false);
  }

  TrainerCardWidget::~TrainerCardWidget ()
  {
  }

  void TrainerCardWidget::Init ()
  {
    SetBackground (*new yap::WidgetBackground (
      "Pictures/TrainerCard/Front.png", true));

    playerSprite_->SetPicture (
      new yap::Sprite ("Test/white.png"));

    // Set layouts size
    mainLayout_->SetSize (yap::Vector2 (750, 465));
    firstLine_->SetSize (yap::Vector2 (750, 75));
    uniqueIDLayout_->SetSize (yap::Vector2 (335, 75));
    secondLine_->SetSize (yap::Vector2 (750, 293));
    secondLinePartLeft_->SetSize (yap::Vector2 (436, 293));
    secondLinePartRight_->SetSize (yap::Vector2 (315, 293));
    nameLayout_->SetSize (yap::Vector2 (360, 45));
    playerDataLayout_->SetSize (yap::Vector2 (375, 176));
    playerDataLabelsLayout_->SetSize (yap::Vector2 (187, 176));
    playerDataValuesLayout_->SetSize (yap::Vector2 (188, 176));

    // Set the labels text size
    name_->SetTextSize (40);
    uniqueID_->SetTextSize (40);
    uniqueIDLabel_->SetTextSize (40);
    nameLabel_->SetTextSize (40);
    name_->SetTextSize (40);
    moneyLabel_->SetTextSize (40);
    money_->SetTextSize (40);
    pokedexLabel_->SetTextSize (40);
    pokedex_->SetTextSize (40);
    gameTimeLabel_->SetTextSize (40);
    gameTime_->SetTextSize (40);

    // Hierarchy construction
    uniqueIDLayout_->AddChild (*uniqueIDLabel_);
    uniqueIDLayout_->AddChild (*uniqueID_);
    firstLine_->AddChild (*uniqueIDLayout_, yap::LayoutBox::Align::RIGHT);

    nameLayout_->AddChild (*nameLabel_, yap::LayoutBox::Align::LEFT);
    nameLayout_->AddChild (*name_);

    secondLinePartLeft_->AddChild (*nameLayout_);

    playerDataLabelsLayout_->AddChild (*moneyLabel_);
    playerDataLabelsLayout_->AddChild (*pokedexLabel_);
    playerDataLabelsLayout_->AddChild (*gameTimeLabel_);

    playerDataValuesLayout_->AddChild (*money_);
    playerDataValuesLayout_->AddChild (*pokedex_);
    playerDataValuesLayout_->AddChild (*gameTime_);

    playerDataLayout_->AddChild (*playerDataLabelsLayout_);
    playerDataLayout_->AddChild (*playerDataValuesLayout_);

    secondLinePartLeft_->AddChild (*playerDataLayout_);

    secondLine_->AddChild (*secondLinePartLeft_);
    secondLine_->AddChild (*secondLinePartRight_);

    mainLayout_->AddChild (*firstLine_, yap::LayoutBox::Align::LEFT);
    mainLayout_->AddChild (*secondLine_, yap::LayoutBox::Align::LEFT);

    AddChild (*mainLayout_);

    // Borders
    mainLayout_->SetBorder (*new yap::WidgetBorder ("Test/black.png"));
    firstLine_->SetBorder (*new yap::WidgetBorder ("Test/red.png"));
    uniqueIDLayout_->SetBorder (*new yap::WidgetBorder ("Test/yellow.png"));
    secondLine_->SetBorder (*new yap::WidgetBorder ("Test/green.png"));
    secondLinePartLeft_->SetBorder (*new yap::WidgetBorder ("Test/blue.png"));
    nameLayout_->SetBorder (*new yap::WidgetBorder ("Test/grey.png"));
    playerDataLayout_->SetBorder (*new yap::WidgetBorder ("Test/cyan.png"));
    playerDataLabelsLayout_->SetBorder (*new yap::WidgetBorder ("Test/orange.png"));
    playerDataValuesLayout_->SetBorder (*new yap::WidgetBorder ("Test/white.png"));
    secondLinePartRight_->SetBorder (*new yap::WidgetBorder ("Test/brown.png"));
    playerSpriteLayout_->SetBorder (*new yap::WidgetBorder ("Test/black.png"));

    mainLayout_->SetPosition (yap::Vector2 (26, 67));
  }

  bool TrainerCardWidget::IsFocusable () const
  {
    return true;
  }

  bool TrainerCardWidget::HandleOnEvent (const yap::GuiEvent& guiEvent)
  {
    if (guiEvent.type == sf::Event::KeyPressed)
    {
      if (guiEvent.key.code == sf::Keyboard::Up)
      {
        return true;
      }

      if (guiEvent.key.code == sf::Keyboard::Down)
      {
        return true;
      }

      if (guiEvent.key.code == sf::Keyboard::Left)
      {
        return true;
      }

      if (guiEvent.key.code == sf::Keyboard::Right)
      {
        return true;
      }

      if (guiEvent.key.code == sf::Keyboard::Return)
      {
        return true;
      }

      if (guiEvent.key.code == sf::Keyboard::Escape)
      {
        Close ();

        return true;
      }
    }

    return false;
  }

  yap::Vector2 TrainerCardWidget::HandleGetSize () const
  {
    return yap::Vector2 (800, 600);
  }

  void TrainerCardWidget::HandleMove (const yap::Vector2& offset)
  {

  }
  void TrainerCardWidget::HandleScale (const yap::Vector2& factor)
  {

  }

  void TrainerCardWidget::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void TrainerCardWidget::HandleShow (bool isVisible)
  {
  }

  void TrainerCardWidget::HandleChangeColor (const sf::Color& color)
  {
  }
  void TrainerCardWidget::HandleUpdate (const yap::Time& dt)
  {
  }

} // namespace ycl