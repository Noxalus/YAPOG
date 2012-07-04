#include "YAPOG/Game/World/Map/BattleSpawnerArea.hpp"
#include "YAPOG/Game/World/Map/MapEvent.hpp"
#include "YAPOG/Game/World/Map/Physics/BoundingBox.hpp"
#include "YAPOG/Game/World/Map/AnyMapEventAction.hpp"
#include "YAPOG/System/StringHelper.hpp"

#include "YAPOG/Log.hpp"
namespace yap
{
  const uint BattleSpawnerArea::DEFAULT_CELL_SIZE = 32;

  const uint BattleSpawnerArea::DEFAULT_WIDTH = 1;
  const uint BattleSpawnerArea::DEFAULT_HEIGHT = 1;

  const int BattleSpawnerArea::DEFAULT_BATTLE_SPAWNING_AREA_Z = 0;
  const int BattleSpawnerArea::DEFAULT_BATTLE_SPAWNING_AREA_H = 1;

  const String BattleSpawnerArea::OBJECT_ENTERING_HANDLER_NAME =
    "ObjectEntering";

  BattleSpawnerArea::BattleSpawnerArea (const ID& id)
    : MapArea (id)
    , width_ (DEFAULT_WIDTH)
    , height_ (DEFAULT_HEIGHT)
    , battleSpawningArea_ ()
  {
  }

  BattleSpawnerArea::~BattleSpawnerArea ()
  {
  }

  BattleSpawnerArea::BattleSpawnerArea (const BattleSpawnerArea& copy)
    : MapArea (copy)
    , width_ (copy.width_)
    , height_ (copy.height_)
    , battleSpawningArea_ (copy.battleSpawningArea_)
  {
  }

  void BattleSpawnerArea::InitArea (uint width, uint height)
  {
    width_ = width;
    height_ = height;

    FloatRect area (
      0,
      0,
      width_ * DEFAULT_CELL_SIZE,
      height_ * DEFAULT_CELL_SIZE);

    SetArea (area);

    HandleInitArea (width, height);
  }

  const uint& BattleSpawnerArea::GetWidth () const
  {
    return width_;
  }

  const uint& BattleSpawnerArea::GetHeight () const
  {
    return height_;
  }

  void BattleSpawnerArea::SetBattleSpawningArea (
    const FloatRect& battleSpawningArea)
  {
    battleSpawningArea_ = battleSpawningArea;

    InitBattleSpawningEvent (battleSpawningArea_);
  }

  void BattleSpawnerArea::HandleInitArea (uint width, uint height)
  {
  }

  void BattleSpawnerArea::InitBattleSpawningEvent (
    const FloatRect& battleSpawningArea)
  {
    MapEvent* battleSpawningEvent = new MapEvent ();

    battleSpawningEvent->AddBoundingBox (
      new BoundingBox (
        Vector2 (battleSpawningArea.left, battleSpawningArea.top),
        Vector2 (battleSpawningArea.width, battleSpawningArea.height),
        DEFAULT_BATTLE_SPAWNING_AREA_Z,
        DEFAULT_BATTLE_SPAWNING_AREA_H));

    battleSpawningEvent->AddAction (
      new AnyMapEventAction (
        MapEventActionType::Enter,
        [this] (MapEventArgs& args)
        {
/*          args.GetTrigger ().OnMoved.AddHandler (
            OBJECT_ENTERING_HANDLER_NAME +
            yap::StringHelper (args.GetTrigger ().GetWorldID ()),
            [this] (
              DynamicWorldObject& sender,
              const Vector2& args)
            {
              DLOGGER.LogLine ("BATTLE TRIGGERED!!");
              });*/

          return true;
        }));

    battleSpawningEvent->AddAction (
      new AnyMapEventAction (
        MapEventActionType::In,
        [this] (MapEventArgs& args)
        {
          return true;
        }));

    battleSpawningEvent->AddAction (
      new AnyMapEventAction (
        MapEventActionType::Leave,
        [this] (MapEventArgs& args)
        {
/*          args.GetTrigger ().OnMoved.RemoveHandler (
            OBJECT_ENTERING_HANDLER_NAME +
            yap::StringHelper (args.GetTrigger ().GetWorldID ()));*/

          return true;
        }));

    AddEvent (battleSpawningEvent);
  }
} // namespace yap
