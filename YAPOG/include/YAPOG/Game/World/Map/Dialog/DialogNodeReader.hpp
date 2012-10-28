#ifndef YAPOG_DIALOGNODEREADER_HPP
# define YAPOG_DIALOGNODEREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/BaseReaderVisitor.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class DialogNode;

  class YAPOG_LIB DialogNodeReader : public BaseReaderVisitor
  {
      DISALLOW_COPY(DialogNodeReader);

    public:

      DialogNodeReader (
        DialogNode& dialogNode,
        const String& xmlRootNodeName);

      virtual ~DialogNodeReader ();

      virtual void Visit (XmlReader& visitable);

    protected:

      String xmlRootNodeName_;

    private:

      DialogNode& dialogNode_;
  };
} // namespace yap

#endif // YAPOG_DIALOGNODEREADER_HPP
