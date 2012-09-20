#include "Gui/GameGuiManager.hpp"

namespace ycl
{
  const bool GameGuiManager::DEFAULT_ADDED_WIDGET_STATE = false;

  GameGuiManager::GameGuiManager ()
    : yap::GuiManager ()
    , currentWidgetName_ ()
    , currentWidget_ (nullptr)
    , gameWidgets_ ()
  {
  }

  GameGuiManager::~GameGuiManager ()
  {
  }

  void GameGuiManager::AddGameWidget (
    const yap::String& name,
    yap::IWidget* gameWidget)
  {
    DEFAULT_ADDED_WIDGET_STATE ? gameWidget->Open () : gameWidget->Close ();

    gameWidgets_.Add (name, gameWidget);
  }

  void GameGuiManager::SetCurrentWidget (const yap::String& name)
  {
    currentWidgetName_ = name;

    currentWidget_ = gameWidgets_[currentWidgetName_];

    RemoveChild (*currentWidget_);
    FrontAddChild (*currentWidget_);

    currentWidget_->Open ();
  }

  bool GameGuiManager::UnsetCurrentWidget ()
  {
    if (currentWidget_ == nullptr)
      return false;

    currentWidget_->Close ();

    currentWidget_ = nullptr;

    return true;
  }

  bool GameGuiManager::HandleOnEvent (const yap::GuiEvent& guiEvent)
  {
    if (currentWidget_ == nullptr)
      return yap::GuiManager::HandleOnEvent (guiEvent);

    return currentWidget_->OnEvent (guiEvent);
  }

  /*
  bool GameGuiManager::HandleOnPriorityEvent (const yap::GuiEvent& guiEvent)
  {
  switch (guiEvent.type)
  {
  case sf::Event::KeyPressed:

  switch (guiEvent.key.code)
  {
  case sf::Keyboard::Escape:

  if (!UnsetCurrentWidget ())
  break;

  return true;

  default: break;
  }

  break;

  default: break;
  }

  return false;
  }
  */
} // namespace ycl
