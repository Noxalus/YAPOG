#include "YAPOG/Graphics/Gui/GameInput/GameInputManager.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/System/Network/Packet.hpp"
#include "YAPOG/System/IO/Log/Logger.hpp"
#include "YAPOG/Graphics/Gui/GuiManager.hpp"
#include "YAPOG/Graphics/ICamera.hpp"
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
#include "YAPOG/Graphics/Gui/MultiLabelWidget.hpp"
#include "YAPOG/Game/Pokemon/Pokedex.hpp"
#include "YAPOG/Game/Pokemon/PokemonTeam.hpp"

#include "GameScreen/GameplayScreen.hpp"
#include "World/Map/Player.hpp"
#include "World/Map/Map.hpp"
#include "Client/Session.hpp"
#include "Gui/ChatWidget.hpp"
#include "Gui/PokedexWidget.hpp"
#include "Gui/PokedexCompositeWidget.hpp"
#include "Gui/PokemonTeamWidget.hpp"

namespace ycl
{
  const yap::ScreenType GameplayScreen::DEFAULT_NAME = "Gameplay";

  const yap::Vector2 GameplayScreen::DEFAULT_WORLD_CAMERA_DEZOOM_FACTOR =
    yap::Vector2 (1.0f, 1.0f);

  GameplayScreen::GameplayScreen (yap::ICamera& worldCamera)
    : BaseScreen (DEFAULT_NAME)
    , world_ ()
    , worldCamera_ (worldCamera)
    , cameraController_ (worldCamera_)
    , player_ (nullptr)
    , moveController_ ()
    , lastForce_ ()
    , pokedex_ (nullptr)
    , chat_ (new ChatWidget ())
  {
  }

  GameplayScreen::~GameplayScreen ()
  {
    delete (chat_);
    chat_ = nullptr;
  }

  void GameplayScreen::HandleInit ()
  {
    BaseScreen::HandleInit ();

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
    /*
    chat_->Init ();
    chat_->ChangeColor (sf::Color (0, 0, 0));
    chat_->Close ();

    chat_->OnMessageSent +=
    [this] (ChatWidget& sender, yap::GameMessage& args)
    {
    session_.GetUser ().SendGameMessage (args);
    };
    */
    worldCamera_.Scale (DEFAULT_WORLD_CAMERA_DEZOOM_FACTOR);

    yap::PokemonTeam* team = new yap::PokemonTeam ();
    PokemonTeamWidget* pokteam = new PokemonTeamWidget (team);
    pokteam->Init ();
    guiManager_->AddChild (*pokteam);
    /*
    yap::Pokedex* pokedexInfo = new yap::Pokedex ();
    for (int i = 1; i < 4; i++)
    {
    yap::PokemonInfo* pok = yap::ObjectFactory::Instance ().
    Create<yap::PokemonInfo> ("PokemonInfo", yap::ID  (i));

    pokedexInfo->AddPokemon (pok);
    pokedexInfo->AddPokemonSeen (pok);
    pokedexInfo->AddPokemonCaught (pok);
    }

    yap::PokemonInfo* pok = yap::ObjectFactory::Instance ().
    Create<yap::PokemonInfo> ("PokemonInfo", yap::ID  (16));

    pokedexInfo->AddPokemon (pok);
    pokedexInfo->AddPokemonSeen (pok);
    pokedexInfo->AddPokemonCaught (pok);

    PokedexWidget* pokedex = new PokedexWidget (pokedexInfo);
    pokedex->Init ();

    guiManager_->AddChild (*pokedex);*/

    /// @warning Commented.
    //guiManager_->AddChild (*pokedex);

    //guiManager_->AddChild (*chat_);
    /// @warning Commented.
    //guiManager_->AddChild (*pokedex);
  }

  void GameplayScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    world_.Update (dt);

    cameraController_.Update (dt);

    UpdatePlayer (dt);

    world_.Draw (context);

    BaseScreen::HandleRun (dt, context);
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

    if (guiEvent.type == sf::Event::KeyPressed)
    {
      if (guiEvent.key.code == sf::Keyboard::F10)
      {
        if (chat_->IsVisible ())
          chat_->Close ();
        else
          chat_->Open ();
        return true;
      }
    }

    if (gameInputManager_.GameInputIsActivated (
      yap::GameInputType::MapAction,
      guiEvent))
    {
      logger_.LogLine ("ACTION START");
      SendGameInput (yap::GameInputType::MapAction, true);
      return true;
    }

    if (gameInputManager_.GameInputIsDeactivated (
      yap::GameInputType::MapAction,
      guiEvent))
    {
      logger_.LogLine ("ACTION END");
      SendGameInput (yap::GameInputType::MapAction, false);
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

  void GameplayScreen::SendGameInput (
    yap::GameInputType gameInputType,
    bool state)
  {
    yap::Packet packet;
    packet.CreateFromType (yap::PacketType::ClientInfoGameInput);

    packet.Write (static_cast<yap::Int16> (gameInputType));
    packet.Write (state);

    session_.SendPacket (packet);
  }
} // namespace ycl
