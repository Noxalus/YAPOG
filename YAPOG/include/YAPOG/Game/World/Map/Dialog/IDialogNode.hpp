#ifndef YAPOG_IDIALOGNODE_HPP
# define YAPOG_IDIALOGNODE_HPP

# include "YAPOG/Game/World/Map/Dialog/DialogNodeExecutionContext.hpp"

namespace yap
{
  template <typename ReturnType>
  struct IDialogNodeVisitor;
  template <typename ReturnType>
  struct IDialogNodeConstVisitor;

  struct IDialogNode
  {
      virtual ~IDialogNode () { }

      virtual bool Accept (IDialogNodeVisitor<bool>& visitor) = 0;
      virtual bool Accept (IDialogNodeConstVisitor<bool>& visitor) const = 0;

      virtual bool Execute (DialogNodeExecutionContext& executionContext) = 0;
  };
} // namespace yap

#endif // YAPOG_IDIALOGNODE_HPP
