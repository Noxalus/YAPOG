#ifndef YAPOG_XMLREADERVISITOR_HPP
# define YAPOG_XMLREADERVISITOR_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/IReaderVisitor.hpp"

namespace yap
{
  class XmlReaderVisitor : public IReaderVisitor
  {
      DISALLOW_COPY(XmlReaderVisitor);

    public:

      virtual ~XmlReaderVisitor ();

      virtual void Visit (XmlReader& visitable);

    protected:

      XmlReaderVisitor ();

    private:

      virtual void HandleVisit (XmlReader& visitable) = 0;
  };
} // namespace yap

#endif // YAPOG_XMLREADERVISITOR_HPP
