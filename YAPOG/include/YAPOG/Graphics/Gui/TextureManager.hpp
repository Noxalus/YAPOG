#ifndef TEXTURE_MANAGER_HPP
# define TEXTURE_MANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"
# include "YAPOG/Graphics/ISpatial.hpp"
# include "YAPOG/Graphics/SpatialInfo.hpp"

namespace yap
{
  class Texture;
  class IDrawingContext;

  class YAPOG_LIB TextureManager :
    public IDrawable,
    public ISpatial
  {
  public:
    TextureManager ();
    TextureManager (Texture& baseTexture, uint width, uint height);
    ~TextureManager ();

    void Init ();
    void UpdatePosition ();

    virtual void Draw (IDrawingContext& context);
    virtual bool IsVisible () const;
    virtual void Show (bool isVisible);
    virtual void ChangeColor (const sf::Color& color);

    virtual const Vector2& GetPosition () const;
    virtual const Vector2& GetSize () const;

    virtual const Vector2& GetTopLeft () const;
    virtual const Vector2& GetBottomRight () const;
    virtual const Vector2& GetCenter () const;

    virtual const sf::FloatRect& GetRectangle () const;

    virtual void Move (const Vector2& offset);
    virtual void Scale (const Vector2& factor);

    virtual void SetPosition (const Vector2& position);
    virtual void SetSize (const Vector2& size);

  private:
    void GetLimits (int& width, int& height);
    mutable SpatialInfo spatialInfo_;
    bool isEnable_;
    sf::Color color_;
    collection::Array<Texture*> textures_;
    bool isVisble_;
    uint width_;
    uint height_;
    Texture* baseTexture_;
  };
} // namespace yap

#endif /* TEXTURE_MANAGER_HPP! */