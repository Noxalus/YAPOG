#ifndef YAPOG_CLIENT_BATTLEPHASEMANAGER_HPP
# define YAPOG_CLIENT_BATTLEPHASEMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"
# include "Battle/BattlePhaseManager.hpp"

namespace ycl
{
  class BattlePhaseManager : public yap::IDrawable
  {
    DISALLOW_COPY (BattlePhaseManager);

  public:
    BattlePhaseManager ();
    virtual ~BattlePhaseManager ();

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
  };
} // namespace ycl

#endif // YAPOG_CLIENT_BATTLEPHASEMANAGER_HPP
