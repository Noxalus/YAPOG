#ifndef YAPOG_IDIALOGRESPONSEACCEPTOR_HPP
# define YAPOG_IDIALOGRESPONSEACCEPTOR_HPP

namespace yap
{
  struct IDialogResponseProvider;

  struct IDialogResponseAcceptor
  {
      virtual ~IDialogResponseAcceptor () { }

      virtual void TreatResponseProvider (
        IDialogResponseProvider& dialogResponseProvider) = 0;
  };
} // namespace yap

#endif // YAPOG_IDIALOGRESPONSEACCEPTOR_HPP
