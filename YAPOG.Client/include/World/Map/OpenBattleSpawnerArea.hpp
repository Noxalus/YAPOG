#ifndef YAPOG_CLIENT_OPENBATTLESPAWNERAREA_HPP
# define YAPOG_CLIENT_OPENBATTLESPAWNERAREA_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/OpenBattleSpawnerArea.hpp"
# include "YAPOG/Graphics/Game/World/Map/IDrawableDynamicWorldObject.hpp"

namespace yap
{
  struct ISprite;
} // namespace yap

namespace ycl
{
  class OpenBattleSpawnerArea : public yap::OpenBattleSpawnerArea
                              , public yap::IDrawableDynamicWorldObject
  {
      DISALLOW_ASSIGN(OpenBattleSpawnerArea);

    public:

      explicit OpenBattleSpawnerArea (const yap::ID& id);
      virtual ~OpenBattleSpawnerArea ();

      void SetBaseSprite (yap::ISprite* baseSprite);

      /// @name ICloneable members.
      /// @{
      virtual OpenBattleSpawnerArea* Clone () const;
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

      OpenBattleSpawnerArea (const OpenBattleSpawnerArea& copy);

      virtual void HandleInitArea (yap::uint width, yap::uint height);

      virtual const yap::String& GetObjectFactoryTypeName () const;

      virtual void HandleUpdate (const yap::Time& dt);

      virtual void HandleMove (const yap::Vector2& offset);

      virtual void HandleDraw (yap::IDrawingContext& context);

      virtual void HandleShow (bool isVisible);
      virtual void HandleChangeColor (const sf::Color& color);

      virtual float HandleGetComparisonPoint () const;

      virtual int HandleGetLayerDepth () const;

    private:

      void AddSprite (yap::uint x, yap::uint y, yap::ISprite* sprite);

      static const bool DEFAULT_VISIBLE_STATE;
      static const sf::Color DEFAULT_COLOR;

      static const int DEFAULT_LAYER_DEPTH;

      static const yap::String OBJECT_FACTORY_TYPE_NAME;

      bool isVisible_;
      sf::Color color_;

      yap::ISprite* baseSprite_;
      yap::collection::List<yap::ISprite*> sprites_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_OPENBATTLESPAWNERAREA_HPP
