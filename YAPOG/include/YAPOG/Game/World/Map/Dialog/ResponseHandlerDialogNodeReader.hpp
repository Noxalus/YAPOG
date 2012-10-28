#ifndef YAPOG_RESPONSEHANDLERDIALOGNODEREADER_HPP
# define YAPOG_RESPONSEHANDLERDIALOGNODEREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/BaseReaderVisitor.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class ResponseHandlerDialogNode;

  class YAPOG_LIB ResponseHandlerDialogNodeReader : public BaseReaderVisitor
  {
      DISALLOW_COPY(ResponseHandlerDialogNodeReader);

    public:

      ResponseHandlerDialogNodeReader (
        ResponseHandlerDialogNode& responseHandlerDialogNode,
        const String& xmlRootNodeName);

      virtual ~ResponseHandlerDialogNodeReader ();

      virtual void Visit (XmlReader& visitable);

    protected:

      String xmlRootNodeName_;

    private:

      ResponseHandlerDialogNode& responseHandlerDialogNode_;
  };
} // namespace yap

#endif // YAPOG_RESPONSEHANDLERDIALOGNODEREADER_HPP
