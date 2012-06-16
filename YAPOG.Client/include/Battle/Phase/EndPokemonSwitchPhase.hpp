#ifndef YAPOG_CLIENT_ENDPOKEMONSWITCHPHASE_HPP
# define YAPOG_CLIENT_ENDPOKEMONSWITCHPHASE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"
# include "YAPOG/Game/Battle/Phase/EndPokemonSwitchPhase.hpp"

namespace yap
{
  class PhaseArgs;
} // namespace yap

namespace ycl
{
  class Battle;
  class BattleInterface;

  class EndPokemonSwitchPhase
    : public yap::EndPokemonSwitchPhase
    , public yap::IDrawable
  {
  public:
    explicit EndPokemonSwitchPhase (Battle& battle, BattleInterface& battleInterface);
    virtual ~EndPokemonSwitchPhase ();

    /// @name BattlePhase members.
    /// @{
    virtual void HandleStart (yap::PhaseArgs* args);
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
    static const float BATTLE_INFO_SPEED;

    bool isVisible_;
    sf::Color color_;

  private:
    Battle& battle_;
    BattleInterface& battleInterface_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_ENDPOKEMONSWITCHPHASE_HPP
