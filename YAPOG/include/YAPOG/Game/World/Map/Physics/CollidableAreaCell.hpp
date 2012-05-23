#ifndef YAPOG_COLLIDABLEAREACELL_HPP
# define YAPOG_COLLIDABLEAREACELL_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/List.hpp"

namespace yap
{
  struct ICollidable;

  class CollidableAreaCell
  {
      DISALLOW_COPY(CollidableAreaCell);

    public:

      typedef collection::List<ICollidable*>::ConstItType ConstItType;
      typedef collection::List<ICollidable*>::ItType ItType;

      CollidableAreaCell ();

      void AddCollidable (ICollidable* collidable);
      void RemoveCollidable (ICollidable* collidable);

      void Clear ();

      ItType begin ();
      ItType end ();

      ConstItType begin () const;
      ConstItType end () const;

    private:

      collection::List<ICollidable*> collidables_;
  };
} // namespace yap

#endif // YAPOG_COLLIDABLEAREACELL_HPP
