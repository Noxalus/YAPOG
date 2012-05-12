#ifndef YAPOG_BASEWRITERVISITOR_HPP
# define YAPOG_BASEWRITERVISITOR_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/IWriterVisitor.hpp"

namespace yap
{
  class YAPOG_LIB BaseWriterVisitor : public IWriterVisitor
  {
      DISALLOW_COPY(BaseWriterVisitor);

    public:

      virtual ~BaseWriterVisitor ();

      /// @name IWriterVisitor members.
      /// @{
      virtual void Visit (XmlWriter& visitable);
      virtual void Visit (DebugLogger& visitable);
      virtual void Visit (DatabaseLogger& visitable);
      virtual void Visit (Packet& visitable);
      virtual void Visit (DatabaseStream& visitable);
      /// @}

    protected:

      BaseWriterVisitor ();
  };
} // namespace yap

#endif // YAPOG_BASEWRITERVISITOR_HPP
