#ifndef YAPOG_IWRITERVISITOR_HPP
# define YAPOG_IWRITERVISITOR_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  struct IPacket;

  class XmlWriter;
  class DebugLogger;
  class DatabaseLogger;
  class DatabaseStream;

  struct IWriterVisitor
  {
    public:

      virtual ~IWriterVisitor () {};

      virtual void Visit (XmlWriter& visitable) = 0;
      virtual void Visit (DebugLogger& visitable) = 0;
      virtual void Visit (DatabaseLogger& visitable) = 0;
      virtual void Visit (IPacket& visitable) = 0;
      virtual void Visit (DatabaseStream& visitable) = 0;
  };
} // namespace yap

#endif // YAPOG_IWRITERVISITOR_HPP
