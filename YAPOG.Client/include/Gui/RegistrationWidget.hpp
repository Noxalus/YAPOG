#ifndef YAPOG_CLIENT_REGISTRATIONWIDGET_HPP
# define YAPOG_CLIENT_REGISTRATIONWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
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

    virtual bool IsFocusable () const;
  protected:
    virtual void HandleMove (const yap::Vector2& offset);
    virtual void HandleScale (const yap::Vector2& factor);
    virtual void HandleDraw (yap::IDrawingContext& context);
    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);
    virtual void HandleUpdate (const yap::Time& dt);

  private:
    yap::VerticalLayout registrationBox_;
    yap::TextBoxWidget loginTextBox_;
    yap::TextBoxWidget passwordTextBox_;
    yap::TextBoxWidget emailTextBox_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_REGISTRATIONWIDGET_HPP
