#ifndef YAPOG_WORLDOBJECT_HPP
# define YAPOG_WORLDOBJECT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Physics/ICollidable.hpp"
# include "YAPOG/Game/Factory/IIDLoadable.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/Game/World/Spatial3Info.hpp"
# include "YAPOG/Game/World/Map/Physics/BoundingBoxCollection.hpp"

namespace yap
{
  class YAPOG_LIB WorldObject : public ICollidable
                              , public IIDLoadable
  {
      DISALLOW_ASSIGN(WorldObject);

    public:

      virtual ~WorldObject ();

      const ID& GetID () const;
      void SetID (const ID& id);

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
      /// @}

      /// @name ICloneable members.
      /// @{
      virtual WorldObject* Clone () const { return nullptr; }
      /// @}

    protected:

      explicit WorldObject (const ID& id);
      WorldObject (const WorldObject& copy);

      virtual void HandleMove (const Vector2& offset);
      virtual void HandleScale (const Vector2& factor);
      virtual void HandleSetZ (int z);
      virtual void HandleSetH (int h);

    private:

      ID id_;
      Spatial3Info spatial3Info_;

      BoundingBoxCollection boundingBoxes_;
  };
} // namespace yap

#endif // YAPOG_WORLDOBJECT_HPP
