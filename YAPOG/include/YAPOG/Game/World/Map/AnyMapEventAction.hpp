#ifndef YAPOG_ANYMAPEVENTACTION_HPP
# define YAPOG_ANYMAPEVENTACTION_HPP

# include <functional>

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/IMapEventAction.hpp"

namespace yap
{
  class MapEventArgs;

  class AnyMapEventAction : public IMapEventAction
  {
      DISALLOW_ASSIGN(AnyMapEventAction);

    public:

      typedef std::function<bool (MapEventArgs&)> CallbackType;

      AnyMapEventAction (CallbackType callback);
      virtual ~AnyMapEventAction ();

      /// @name IMapEventAction members.
      /// @{
      virtual bool Execute (MapEventArgs& args);
      /// @}

    private:

      CallbackType callback_;
  };
} // namespace yap

#endif // YAPOG_ANYMAPEVENTACTION_HPP
