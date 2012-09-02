#ifndef YAPOG_WARPMAPEVENTACTION_HPP
# define YAPOG_WARPMAPEVENTACTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/BaseMapEventAction.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  class WarpMapEventAction : public BaseMapEventAction
  {
      DISALLOW_ASSIGN(WarpMapEventAction);

    public:

      WarpMapEventAction (const ID& mapWorldID, const Vector2& mapPoint);
      virtual ~WarpMapEventAction ();

      virtual void VisitPlayer (IPlayer& visitable);

      /// @name ICloneable members.
      /// @{
      virtual WarpMapEventAction* Clone () const;
      /// @}

    protected:

      WarpMapEventAction (const WarpMapEventAction& copy);

    private:

      ID mapWorldID_;
      Vector2 mapPoint_;
  };
} // namespace yap

#endif // YAPOG_WARPMAPEVENTACTION_HPP
