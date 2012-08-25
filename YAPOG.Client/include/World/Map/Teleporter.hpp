#ifndef YAPOG_CLIENT_TELEPORTER_HPP
# define YAPOG_CLIENT_TELEPORTER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Teleporter.hpp"
# include "YAPOG/Graphics/Game/World/Map/IDrawableDynamicWorldObject.hpp"

namespace ycl
{
  class Teleporter : public yap::Teleporter
                   , public yap::IDrawableDynamicWorldObject
  {
      DISALLOW_ASSIGN(Teleporter);

    public:

      explicit Teleporter (const yap::ID& id);
      virtual ~Teleporter ();

      void Init (
        const yap::ID& mapWorldID,
        const yap::Vector2& mapPoint,
        const yap::FloatRect& area);

      /// @name ICloneable members.
      /// @{
      virtual Teleporter* Clone () const;
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

      /// @name IDrawableDynamicWorldObject members.
      /// @{
      virtual yap::Event<
        IDrawableDynamicWorldObject&,
        const yap::Vector2&>& OnOrderStateChangedEvent ();
      /// @}

      yap::Event<
        IDrawableDynamicWorldObject&,
        const yap::Vector2&> OnOrderStateChanged;

    protected:

      Teleporter (const Teleporter& copy);

      virtual const yap::String& GetObjectFactoryTypeName () const;

      virtual void HandleDraw (yap::IDrawingContext& context);

      virtual void HandleShow (bool isVisible);
      virtual void HandleChangeColor (const sf::Color& color);

      virtual float HandleGetComparisonPoint () const;

      virtual int HandleGetLayerDepth () const;

      virtual void HandleChangeWorldDrawingPolicy (
        const yap::IWorldDrawingPolicy& worldDrawingPolicy);

    private:

      static const bool DEFAULT_VISIBLE_STATE;
      static const sf::Color DEFAULT_COLOR;

      static const int DEFAULT_LAYER_DEPTH;

      static const yap::String OBJECT_FACTORY_TYPE_NAME;

      bool isVisible_;
      sf::Color color_;

      const yap::IWorldDrawingPolicy* worldDrawingPolicy_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_TELEPORTER_HPP
