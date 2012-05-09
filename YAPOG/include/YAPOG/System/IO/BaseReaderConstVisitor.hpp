#ifndef YAPOG_BASEREADERCONSTVISITOR_HPP
# define YAPOG_BASEREADERCONSTVISITOR_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/IReaderConstVisitor.hpp"

namespace yap
{
  class YAPOG_LIB BaseReaderConstVisitor : public IReaderConstVisitor
  {
      DISALLOW_COPY(BaseReaderConstVisitor);

    public:

      virtual ~BaseReaderConstVisitor ();

      /// @name IReaderVisitor members.
      /// @{
      virtual void Visit (const XmlReader& visitable);
      virtual void Visit (const Packet& visitable);
      /// @}

    protected:

      BaseReaderConstVisitor ();
  };
} // namespace yap

#endif // YAPOG_BASEREADERCONSTVISITOR_HPP
