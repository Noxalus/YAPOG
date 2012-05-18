#ifndef YAPOG_BOUNDINGBOXCOLLECTION_HPP
# define YAPOG_BOUNDINGBOXCOLLECTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/ISpatial3.hpp"
# include "YAPOG/Game/World/Spatial3Info.hpp"
# include "YAPOG/Collection/List.hpp"

namespace yap
{
  class BoundingBox;

  class YAPOG_LIB BoundingBoxCollection : public ISpatial3
  {
      DISALLOW_ASSIGN(BoundingBoxCollection);

    public:

      BoundingBoxCollection ();
      virtual ~BoundingBoxCollection ();

      BoundingBoxCollection (const BoundingBoxCollection& copy);

      void AddBoundingBox (BoundingBox* boundingBox);
      void RemoveBoundingBox (BoundingBox* boundingBox);

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

    private:

      Spatial3Info spatial3Info_;

      collection::List<BoundingBox*> boundingBoxes_;
  };
} // namespace yap

#endif // YAPOG_BOUNDINGBOXCOLLECTION_HPP
