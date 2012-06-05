#ifndef YAPOG_CLIENT_CHATWIDGET_HPP
# define YAPOG_CLIENT_CHATWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/Graphics/Gui/GuiEvent.hpp"

#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
#include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
#include "YAPOG/Graphics/Gui/DialogBoxWidget.hpp"
#include "YAPOG/Graphics/Gui/TextBoxWidget.hpp"

# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  class Chat;
}

namespace ycl
{
  typedef yap::collection::Array<yap::Label*> TabTitleType;
  typedef 
    yap::collection::Array<
    std::pair<yap::UInt32, yap::String>>      ResponseType;
  class ChatWidget : public yap::BaseWidget
  {
    DISALLOW_COPY(ChatWidget);

  public:
    ChatWidget ();
    virtual                 ~ChatWidget();

    void                    Init ();
    virtual bool            IsFocusable () const;

  protected:
    virtual yap::Vector2    HandleGetSize () const;
    virtual void            HandleMove (const yap::Vector2& offset);
    virtual void            HandleScale (const yap::Vector2& factor);

    virtual void            HandleDraw (yap::IDrawingContext& context);
    virtual bool            HandleOnEvent (const yap::GuiEvent& guiEvent);

    virtual void            HandleShow (bool isVisible);
    virtual void            HandleChangeColor (const sf::Color& color);

    virtual void            HandleUpdate (const yap::Time& dt);

  private:
    void                    InitTab ();
    void                    InitDial ();
    void                    InitEntry ();
    void                    DisplayResponse (ResponseType response);

    yap::Chat*              chat_;
    yap::String             line_;
    yap::TextBoxWidget*     lineCatcher_;
    TabTitleType            tabTitle_;
    yap::HorizontalLayout*  tabLayout_;
    yap::Label*             dialog_;
    yap::HorizontalLayout*  dialLayout_;
    yap::HorizontalLayout*  entryLayout_;
    yap::VerticalLayout*    bigLayout_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_CHATWIDGET_HPP