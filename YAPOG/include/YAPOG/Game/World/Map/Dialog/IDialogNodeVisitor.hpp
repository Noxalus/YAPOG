#ifndef YAPOG_IDIALOGNODEVISITOR_HPP
# define YAPOG_IDIALOGNODEVISITOR_HPP

namespace yap
{
  class DialogNode;
  class ResponseHandlerDialogNode;

  template <typename ReturnType>
  struct IDialogNodeVisitor
  {
      virtual ~IDialogNodeVisitor () { }

      virtual ReturnType VisitDialogNode (
        DialogNode& visitable) = 0;

      virtual ReturnType VisitResponseHandlerDialogNode (
        ResponseHandlerDialogNode& visitable) = 0;
  };
} // namespace yap

#endif // YAPOG_IDIALOGNODEVISITOR_HPP
