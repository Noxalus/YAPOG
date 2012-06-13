#ifndef YAPOG_CLIENT_BEGINTURNPHASE_HPP
# define YAPOG_CLIENT_BEGINTURNPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"
# include "YAPOG/Game/Battle/Phase/BeginTurnPhase.hpp"

namespace ycl
{
  class Battle;

  class BeginTurnPhase
    : public yap::BeginTurnPhase
    , public yap::IDrawable
  {
  public:
    explicit BeginTurnPhase (Battle& battle);
    virtual ~BeginTurnPhase ();

    /// @name BattlePhase members.
    /// @{
    virtual void HandleStart ();
    virtual void HandleUpdate (const yap::Time& dt);
    virtual void HandleEnd ();
    /// @}

    /// @name IDrawable members.
    /// @{
    virtual void Draw (yap::IDrawingContext& context);

    virtual bool IsVisible () const;
    virtual void Show (bool isVisible);

    virtual void ChangeColor (const sf::Color& color);
    /// @}

  protected:
    virtual void HandleDraw (yap::IDrawingContext& context);
    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    static const bool DEFAULT_VISIBLE_STATE;
    static const sf::Color DEFAULT_COLOR;

    bool isVisible_;
    sf::Color color_;

  private:
    Battle& battle_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_BEGINTURNPHASE_HPP
