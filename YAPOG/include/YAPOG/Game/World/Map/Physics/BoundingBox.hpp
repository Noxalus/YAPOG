#ifndef YAPOG_BOUNDINGBOX_HPP
# define YAPOG_BOUNDINGBOX_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/Game/World/Map/Physics/ICollidable.hpp"
# include "YAPOG/Game/World/Spatial3Info.hpp"

namespace yap
{
  class YAPOG_LIB BoundingBox : public ICollidable
  {
      DISALLOW_ASSIGN(BoundingBox);

    public:

      BoundingBox ();
      BoundingBox (
        const Vector2& position,
        const Vector2& size,
        int z,
        int h);
      virtual ~BoundingBox ();

      BoundingBox (const BoundingBox& copy);

      /// @name ISpatial members.
      /// @{
      virtual const Vector2& GetPosition () const;
      virtual const Vector2& GetSize () const;

      virtual const Vector2& GetTopLeft () const;
      virtual const Vector2& GetBottomRight () const;
      virtual const Vector2& GetCenter () const;

      virtual const FloatRect& GetRectangle () const;

      virtual void Move (const Vector2& offset);
      virtual void Scale (const Vector2& factor);

      virtual void SetPosition (const Vector2& position);
      virtual void SetSize (const Vector2& size);
      /// @}

      /// @name ISpatial3 members.
      /// @{
      virtual const int& GetZ () const;
      virtual void SetZ (int z);

      virtual const int& GetH () const;
      virtual void SetH (int h);
      /// @}

      /// @name ICollidable members.
      /// @{
      virtual bool CollidesWith (const ICollidable& other) const;
      virtual bool CollidesWith (
        const ICollidable& other,
        const Vector2& offset) const;
      /// @}

    private:

      Spatial3Info spatial3Info_;
  };
} // namespace yap

#endif // YAPOG_BOUNDINGBOX_HPP
