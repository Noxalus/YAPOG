#ifndef YAPOG_CLIENT_REGISTRATIONWIDGET_HPP
# define YAPOG_CLIENT_REGISTRATIONWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/Label.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
# include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
# include "YAPOG/Graphics/Gui/TextBoxWidget.hpp"

namespace ycl
{
  class RegistrationWidget : public yap::BaseWidget
  {
    DISALLOW_COPY(RegistrationWidget);

  public:
    RegistrationWidget();
    virtual ~RegistrationWidget ();

    void Init ();

    /// @name Getters.
    /// @{
    yap::TextBoxWidget& GetLoginTextBox ();
    yap::TextBoxWidget& GetPasswordTextBox ();
    yap::TextBoxWidget& GetEmailTextBox ();
    /// @}

    /// @name Setters.
    /// @{
    void SetErrorText (const yap::String& error);
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
    yap::VerticalLayout   registrationBox_;
    yap::HorizontalLayout loginBox_;
    yap::TextBoxWidget    loginTextBox_;
    yap::Label            loginLabel_;
    yap::HorizontalLayout passwordBox_;
    yap::TextBoxWidget    passwordTextBox_;
    yap::Label            passwordLabel_;
    yap::HorizontalLayout emailBox_;
    yap::TextBoxWidget    emailTextBox_;
    yap::Label            emailLabel_;
    yap::Label            errorLabel_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_REGISTRATIONWIDGET_HPP
