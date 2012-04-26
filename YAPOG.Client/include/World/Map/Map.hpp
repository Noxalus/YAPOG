#ifndef YAPOG_CLIENT_MAP_HPP
# define YAPOG_CLIENT_MAP_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Map.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"
# include "YAPOG/Graphics/Game/World/Map/TileLayerStack.hpp"

class Map : public yap::Map
          , public yap::IDrawable
{
    DISALLOW_ASSIGN(Map);

  public:

    Map (const yap::ID& id);
    virtual ~Map ();

    void AddTileLayer (uint height, yap::TileLayoutHandler* tileLayoutHandler);

    /// @name ICloneable members.
    /// @{
    virtual Map* Clone () const;
    /// @}

    /// @name IDrawable members.
    /// @{
    virtual void Draw (yap::IDrawingContext& context);

    virtual bool IsVisible () const;
    virtual void Show (bool isVisible);

    virtual void ChangeColor (const sf::Color& color);
    /// @}

  protected:

    /// @brief Copy constructor for Clone member.
    Map (const Map& copy);

  private:

    virtual void HandleSetSize (uint width, uint height);

    yap::TileLayerStack tileLayers_;
};

#endif // YAPOG_CLIENT_MAP_HPP
