#ifndef YAPOG_CLIENT_MAPELEMENT_HPP
# define YAPOG_CLIENT_MAPELEMENT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/MapElement.hpp"
# include "YAPOG/Graphics/Game/World/Map/IDrawableWorldObject.hpp"

namespace yap
{
  struct ISprite;
} // namespace yap

namespace ycl
{
  class MapElement : public yap::MapElement
                   , public yap::IDrawableWorldObject
  {
      DISALLOW_ASSIGN(MapElement);

    public:

      explicit MapElement (const yap::ID& id);
      virtual ~MapElement ();

      void SetSprite (yap::ISprite* sprite);

      void SetLayerDepth (int layerDepth);

      /// @name ICloneable members.
      /// @{
      virtual MapElement* Clone () const;
      /// @}

      /// @name IDrawable members.
      /// @{
      virtual void Draw (yap::IDrawingContext& context);

      virtual bool IsVisible () const;
      virtual void Show (bool isVisible);

      virtual void ChangeColor (const sf::Color& color);
      /// @}

      /// @name IDrawableWorldObject members.
      /// @{
      virtual float GetComparisonPoint () const;

      virtual int GetLayerDepth () const;

      virtual void ChangeWorldDrawingPolicy (
        const yap::IWorldDrawingPolicy& worldDrawingPolicy);
      /// @}

    protected:

      MapElement (const MapElement& copy);

      virtual void HandleUpdate (const yap::Time& dt);

      virtual yap::Vector2 HandleGetSize () const;

      virtual void HandleMove (const yap::Vector2& offset);

      virtual void HandleDraw (yap::IDrawingContext& context);

      virtual void HandleChangeColor (const sf::Color& color);

      virtual float HandleGetComparisonPoint () const;

      virtual int HandleGetLayerDepth () const;

      virtual void HandleChangeWorldDrawingPolicy (
        const yap::IWorldDrawingPolicy& worldDrawingPolicy);

    private:

      static const bool DEFAULT_VISIBLE_STATE;
      static const sf::Color DEFAULT_COLOR;

      static const int DEFAULT_LAYER_DEPTH;

      bool isVisible_;
      sf::Color color_;

      int layerDepth_;
      const yap::IWorldDrawingPolicy* worldDrawingPolicy_;

      yap::ISprite* sprite_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_MAPELEMENT_HPP
