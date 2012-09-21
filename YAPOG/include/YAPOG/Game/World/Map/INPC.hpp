#ifndef YAPOG_INPC_HPP
# define YAPOG_INPC_HPP

# include "YAPOG/Game/World/Map/Dialog/IDialogActor.hpp"

namespace yap
{
  struct IDynamicWorldObjectVisitor;
  struct IDynamicWorldObjectConstVisitor;

  /// @brief Represents the set of actions that
  /// a non playable character can perform.
  struct INPC : public IDialogActor
  {
      virtual ~INPC () { }

      virtual void Accept (IDynamicWorldObjectVisitor& visitor) = 0;
      virtual void Accept (IDynamicWorldObjectConstVisitor& visitor) const = 0;
  };
} // namespace yap

#endif // YAPOG_INPC_HPP
