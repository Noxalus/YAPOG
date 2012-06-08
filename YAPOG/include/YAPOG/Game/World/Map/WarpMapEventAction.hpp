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

      WarpMapEventAction (
        MapEventActionType type,
        const ID& mapWorldID,
        const Vector2& point);
      virtual ~WarpMapEventAction ();

      virtual void VisitPlayer (IPlayer& visitable);

    private:

      ID mapWorldID_;
      Vector2 point_;
  };
} // namespace yap

#endif // YAPOG_WARPMAPEVENTACTION_HPP
