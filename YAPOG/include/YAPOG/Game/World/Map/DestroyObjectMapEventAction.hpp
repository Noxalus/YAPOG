#ifndef YAPOG_DESTROYOBJECTMAPEVENTACTION_HPP
# define YAPOG_DESTROYOBJECTMAPEVENTACTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/BaseMapEventAction.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  class YAPOG_LIB DestroyObjectMapEventAction : public BaseMapEventAction
  {
      DISALLOW_ASSIGN(DestroyObjectMapEventAction);

    public:

      DestroyObjectMapEventAction ();
      virtual ~DestroyObjectMapEventAction ();

      void SetTargetWorldID (const ID& targetWorldID);

      virtual void VisitPlayer (IPlayer& visitable);

      /// @name ICloneable members.
      /// @{
      virtual DestroyObjectMapEventAction* Clone () const;
      /// @}

    protected:

      DestroyObjectMapEventAction (const DestroyObjectMapEventAction& copy);

    private:

      ID targetWorldID_;
  };
} // namespace yap

#endif // YAPOG_DESTROYOBJECTMAPEVENTACTION_HPP
