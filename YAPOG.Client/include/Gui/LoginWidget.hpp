#ifndef YAPOG_CLIENT_LOGINWIDGET_HPP
# define YAPOG_CLIENT_LOGINWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
# include "YAPOG/Graphics/Gui/TextBoxWidget.hpp"
# include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"

namespace ycl
{
  class LoginWidget : public yap::BaseWidget
  {
    DISALLOW_COPY(LoginWidget);

  public:
    LoginWidget();
    virtual ~LoginWidget ();

    void Init ();

    /// @name Getters.
    /// @{
    yap::TextBoxWidget& GetLoginTextBox ();
    yap::TextBoxWidget& GetPasswordTextBox ();
    /// @}

    virtual bool IsFocusable () const;
  protected:
    virtual void HandleMove (const yap::Vector2& offset);
    virtual void HandleScale (const yap::Vector2& factor);
    virtual void HandleDraw (yap::IDrawingContext& context);
    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);
    virtual void HandleUpdate (const yap::Time& dt);

  private:
    /// @name Layouts.
    /// @{
    yap::VerticalLayout widgetBox_;
    yap::HorizontalLayout loginBox_;
    yap::HorizontalLayout passwordBox_;
    /// @}

    /// @name Labels.
    /// @{
    yap::Label loginLabel_;
    yap::Label passwordLabel_;
    /// @}

    /// @name TextWidget.
    /// @{
    yap::TextBoxWidget loginTextBox_;
    yap::TextBoxWidget passwordTextBox_;
    /// @}
  };
} // namespace ycl

#endif // YAPOG_CLIENT_LOGINWIDGET_HPP
