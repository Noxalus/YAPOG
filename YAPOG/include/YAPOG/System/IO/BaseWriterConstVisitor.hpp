#ifndef YAPOG_BASEWRITERCONSTVISITOR_HPP
# define YAPOG_BASEWRITERCONSTVISITOR_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/IWriterConstVisitor.hpp"

namespace yap
{
  class YAPOG_LIB BaseWriterConstVisitor : public IWriterConstVisitor
  {
      DISALLOW_COPY(BaseWriterConstVisitor);

    public:

      virtual ~BaseWriterConstVisitor ();

      /// @name IWriterVisitor members.
      /// @{
      virtual void Visit (const XmlWriter& visitable);
      virtual void Visit (const DebugLogger& visitable);
      virtual void Visit (const DatabaseLogger& visitable);
      virtual void Visit (const Packet& visitable);
      virtual void Visit (const DatabaseStream& visitable);
      /// @}

    protected:

      BaseWriterConstVisitor ();
  };
} // namespace yap

#endif // YAPOG_BASEWRITERCONSTVISITOR_HPP
