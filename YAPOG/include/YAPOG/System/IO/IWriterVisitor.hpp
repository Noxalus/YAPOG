#ifndef YAPOG_IWRITERVISITOR_HPP
# define YAPOG_IWRITERVISITOR_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  class XmlWriter;
  class DebugLogger;
  class DatabaseLogger;
  class Packet;

  struct YAPOG_LIB IWriterVisitor
  {
    public:

      virtual ~IWriterVisitor () {};

      virtual void Visit (XmlWriter& visitable) = 0;
      virtual void Visit (DebugLogger& visitable) = 0;
      virtual void Visit (DatabaseLogger& visitable) = 0;
      virtual void Visit (Packet& visitable) = 0;
  };
} // namespace yap

#endif // YAPOG_IWRITERVISITOR_HPP
