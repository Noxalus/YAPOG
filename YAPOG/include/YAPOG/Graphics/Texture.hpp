#ifndef YAPOG_TEXTURE_HPP
# define YAPOG_TEXTURE_HPP

# include <SFML/Graphics/Texture.hpp>
# include <SFML/Graphics/Sprite.hpp>
# include <SFML/Graphics/Rect.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/Graphics/SpatialInfo.hpp"

namespace yap
{
  /// @brief Base graphical element.
  /// Overlay of SFML Sprite.
  class YAPOG_LIB Texture : public IDrawable
  {
      DISALLOW_COPY(Texture);

    public:

      Texture ();
      explicit Texture (const String& name);
      Texture (const String& name, const sf::IntRect& rect);
      virtual ~Texture ();

      void LoadFromFile (const String& name);

      void SetTextureRect (const sf::IntRect& rect);

      /// @name ISpatial members.
      /// @{
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
      /// @}

      /// @name IDrawable members.
      /// @{
      virtual void Draw (IDrawingContext& context);

      virtual bool IsVisible () const;
      virtual void Show (bool isVisible);

      virtual void ChangeColor (const sf::Color& color);
      /// @}

    private:

      static const bool DEFAULT_VISIBLE_STATE;

      SpatialInfo spatialInfo_;
      sf::Texture* innerTexture_;
      sf::Sprite sprite_;

      bool isVisible_;
  };
} // namespace yap

#endif // YAPOG_TEXTURE_HPP
