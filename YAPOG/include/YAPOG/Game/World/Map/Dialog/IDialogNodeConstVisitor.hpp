#ifndef YAPOG_IDIALOGNODECONSTVISITOR_HPP
# define YAPOG_IDIALOGNODECONSTVISITOR_HPP

namespace yap
{
  class DialogNode;
  class ResponseHandlerDialogNode;

  template <typename ReturnType>
  struct IDialogNodeConstVisitor
  {
      virtual ~IDialogNodeConstVisitor () { }

      virtual ReturnType VisitDialogNode (
        const DialogNode& visitable) = 0;

      virtual ReturnType VisitResponseHandlerDialogNode (
        const ResponseHandlerDialogNode& visitable) = 0;
  };
} // namespace yap

#endif // YAPOG_IDIALOGNODECONSTVISITOR_HPP
