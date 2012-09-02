#ifndef YAPOG_ANYMAPEVENTACTION_HPP
# define YAPOG_ANYMAPEVENTACTION_HPP

# include <functional>

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/BaseMapEventAction.hpp"

namespace yap
{
  class MapEventArgs;

  class YAPOG_LIB AnyMapEventAction : public BaseMapEventAction
  {
      DISALLOW_ASSIGN(AnyMapEventAction);

    public:

      typedef std::function<
        bool (MapEventActionType, MapEventArgs&)> CallbackType;

      explicit AnyMapEventAction (CallbackType callback);
      virtual ~AnyMapEventAction ();

      /// @name ICloneable members.
      /// @{
      virtual AnyMapEventAction* Clone () const;
      /// @}

    protected:

      AnyMapEventAction (const AnyMapEventAction& copy);

      virtual bool HandleExecute (MapEventArgs& args);

    private:

      CallbackType callback_;
  };
} // namespace yap

#endif // YAPOG_ANYMAPEVENTACTION_HPP
