#include "YAPOG/Graphics/Gui/GameInput/GameInputManager.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/System/Network/Packet.hpp"
#include "YAPOG/System/IO/Log/Logger.hpp"
#include "YAPOG/Graphics/Gui/GuiManager.hpp"
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
#include "YAPOG/Graphics/Gui/TextBoxWidget.hpp"
#include "YAPOG/Graphics/Gui/GridMenu.hpp"

#include "GameScreen/GameplayScreen.hpp"
#include "World/Map/Player.hpp"
#include "World/Map/Map.hpp"
#include "Client/Session.hpp"
#include "Gui/ChatWidget.hpp"
#include "Gui/PokedexWidget.hpp"
#include "Gui/PokedexCompositeWidget.hpp"

namespace ycl
{
  const yap::ScreenType GameplayScreen::DEFAULT_NAME = "Gameplay";

  GameplayScreen::GameplayScreen (yap::ICamera& worldCamera)
    : BaseScreen (DEFAULT_NAME)
    , world_ ()
    , cameraController_ (worldCamera)
    , player_ (nullptr)
    , moveController_ ()
    , lastForce_ ()
    , pokedex_ (nullptr)
  {
    session_.GetUser ().OnPlayerCreated += [&] (
      const User& sender,
      Player* args)
    {
      SetPlayer (args);
    };

    world_.OnMapChanged += [&] (
      const World& sender,
      const yap::ChangeEventArgs<Map*>& args)
    {
      SetCurrentMap (*args.Current);
    };

    session_.GetUser ().SetWorld (&world_);
  }

  GameplayScreen::~GameplayScreen ()
  {
  }

  void GameplayScreen::HandleInit ()
  {
    BaseScreen::HandleInit ();

    yap::GridMenu* menu = new yap::GridMenu (yap::Vector2 (2, 2), yap::Padding (5,5,5,5), yap::Padding (5,5,5,5), true);
    menu->SetSelectedBorder (*new yap::WidgetBorder ("Test/black.png"));
    yap::MenuItem* item1 = new yap::MenuItem (false);
    item1->SetContent ("Item1");
    yap::MenuItem* item2 = new yap::MenuItem (false);
    item2->SetContent ("Item2");
    yap::MenuItem* item3 = new yap::MenuItem (false);
    item3->SetContent ("Item3");
    yap::MenuItem* item4 = new yap::MenuItem (false);
    item4->SetContent ("Item4");

    item1->SetSize (yap::Vector2 (128, 64));
    item2->SetSize (yap::Vector2 (128, 64));
    item3->SetSize (yap::Vector2 (128, 64));
    item4->SetSize (yap::Vector2 (128, 64));

    menu->AddChild (*item1);
    menu->AddChild (*item2);
    menu->AddChild (*item3);
    menu->AddChild (*item4);

   /* pokedex_ = new PokedexWidget ();
    pokedex_->Init ();    

    guiManager_->AddChild (*pokedex_);  */
    guiManager_->AddChild (*menu);
  }

  const yap::ScreenType& GameplayScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    world_.Update (dt);

    cameraController_.Update (dt);

    UpdatePlayer (dt);

    world_.Draw (context);
    /*
    yap::PokemonInfo* activatedPokemon = pokedex_->GetActivatedPokemon ();
    if (activatedPokemon != nullptr)
    {
      pokedexInfo_->Open ();
      pokedex_->Close ();
    }
    */
    return BaseScreen::HandleRun (dt, context);
  }

  bool GameplayScreen::HandleOnEvent (const yap::GuiEvent& guiEvent)
  {
    if (gameInputManager_.GameInputIsActivated (
      yap::GameInputType::Down,
      guiEvent))
    {
      moveController_.EnableDirection (yap::Direction::South);
      return true;
    }

    if (gameInputManager_.GameInputIsActivated (
      yap::GameInputType::Up,
      guiEvent))
    {
      moveController_.EnableDirection (yap::Direction::North);
      return true;
    }

    if (gameInputManager_.GameInputIsActivated (
      yap::GameInputType::Left,
      guiEvent))
    {
      moveController_.EnableDirection (yap::Direction::West);
      return true;
    }

    if (gameInputManager_.GameInputIsActivated (
      yap::GameInputType::Right,
      guiEvent))
    {
      moveController_.EnableDirection (yap::Direction::East);
      return true;
    }

    if (gameInputManager_.GameInputIsDeactivated (
      yap::GameInputType::Down,
      guiEvent))
    {
      moveController_.DisableDirection (yap::Direction::South);
      return true;
    }

    if (gameInputManager_.GameInputIsDeactivated (
      yap::GameInputType::Up,
      guiEvent))
    {
      moveController_.DisableDirection (yap::Direction::North);
      return true;
    }

    if (gameInputManager_.GameInputIsDeactivated (
      yap::GameInputType::Left,
      guiEvent))
    {
      moveController_.DisableDirection (yap::Direction::West);
      return true;
    }

    if (gameInputManager_.GameInputIsDeactivated (
      yap::GameInputType::Right,
      guiEvent))
    {
      moveController_.DisableDirection (yap::Direction::East);
      return true;
    }

    return false;
  }

  Map& GameplayScreen::GetCurrentMap ()
  {
    return world_.GetCurrentMap ();
  }

  void GameplayScreen::SetCurrentMap (Map& map)
  {
    cameraController_.SetBounds (
      yap::FloatRect (
      yap::Vector2 (),
      map.GetSize ()));
  }

  void GameplayScreen::SetPlayer (Player* player)
  {
    player_ = player;

    moveController_.SetValue (player_->GetMaxVelocity ());

    cameraController_.SetTarget (*player);
    cameraController_.SetVelocityFactor (player->GetMaxVelocity ());
  }

  void GameplayScreen::UpdatePlayer (const yap::Time& dt)
  {
    if (player_ == nullptr)
      return;

    const yap::Vector2& force = moveController_.GetForce ();

    if (lastForce_ == force)
      return;

    SendApplyForce (force);

    player_->ApplyForce (force);

    lastForce_ = force;
  }

  void GameplayScreen::SendApplyForce (const yap::Vector2& force)
  {
    yap::Packet packet;
    packet.CreateFromType (yap::PacketType::ClientInfoApplyForce);

    packet.Write (force);

    session_.SendPacket (packet);
  }
} // namespace ycl
