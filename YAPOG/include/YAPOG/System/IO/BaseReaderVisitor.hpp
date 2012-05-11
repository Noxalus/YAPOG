#ifndef YAPOG_BASEREADERVISITOR_HPP
# define YAPOG_BASEREADERVISITOR_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/IReaderVisitor.hpp"

namespace yap
{
  class YAPOG_LIB BaseReaderVisitor : public IReaderVisitor
  {
      DISALLOW_COPY(BaseReaderVisitor);

    public:

      virtual ~BaseReaderVisitor ();

      /// @name IReaderVisitor members.
      /// @{
      virtual void Visit (XmlReader& visitable);
      virtual void Visit (Packet& visitable);
      virtual void Visit (DatabaseStream& visitable);
      /// @}

    protected:

      BaseReaderVisitor ();
  };
} // namespace yap

#endif // YAPOG_BASEREADERVISITOR_HPP
