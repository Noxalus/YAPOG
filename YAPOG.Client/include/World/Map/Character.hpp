#ifndef YAPOG_CLIENT_CHARACTER_HPP
# define YAPOG_CLIENT_CHARACTER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Character.hpp"
# include "YAPOG/Graphics/Game/World/Map/IDrawableWorldObject.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Graphics/Game/Sprite/SpriteSet.hpp"
# include "YAPOG/Collection/Map.hpp"

namespace ycl
{
  class Character : public yap::Character
                  , public yap::IDrawableWorldObject
  {
      DISALLOW_ASSIGN(Character);

    public:

      virtual ~Character ();

      void AddSprite (
        const yap::String& state,
        yap::SpriteSet<yap::Direction>* directionSprite);

      /// @name IDrawable members.
      /// @{
      virtual void Draw (yap::IDrawingContext& context);

      virtual bool IsVisible () const;
      virtual void Show (bool isVisible);

      virtual void ChangeColor (const sf::Color& color);
      /// @}

      /// @name IDrawableWorldObject members.
      /// @{
      virtual int CompareOrder (const yap::IDrawableWorldObject& other) const;

      virtual float GetComparisonPoint () const;
      /// @}

    protected:

      explicit Character (const yap::ID& id);

      Character (const Character& copy);

      virtual void HandleUpdate (const yap::Time& dt);

      virtual void HandleSetState (const yap::String& state);

      virtual void HandleMove (const yap::Vector2& offset);

      virtual void HandleSetDirection (yap::Direction direction);

      virtual void HandleDraw (yap::IDrawingContext& context);

      virtual void HandleShow (bool isVisible);
      virtual void HandleChangeColor (const sf::Color& color);

      virtual int HandleCompareOrder (
        const yap::IDrawableWorldObject& other) const;

      virtual float HandleGetComparisonPoint () const;

    private:

      static const bool DEFAULT_VISIBLE_STATE;
      static const sf::Color DEFAULT_COLOR;

      bool isVisible_;
      sf::Color color_;

      yap::SpriteSet<yap::String>* sprites_;
      yap::collection::Map<
        yap::String,
        yap::SpriteSet<yap::Direction>*> directionSprites_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_CHARACTER_HPP
