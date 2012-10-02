#ifndef YAPOG_IDIALOGRESPONSEACCEPTOR_HPP
# define YAPOG_IDIALOGRESPONSEACCEPTOR_HPP

namespace yap
{
  class ResponseHandlerDialogNode;

  struct IDialogResponseAcceptor
  {
      virtual ~IDialogResponseAcceptor () { }

      virtual void TreatNode (ResponseHandlerDialogNode& dialogNode) = 0;
  };
} // namespace yap

#endif // YAPOG_IDIALOGRESPONSEACCEPTOR_HPP
