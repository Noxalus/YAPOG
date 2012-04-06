#ifndef YAPOG_IWRITERCONSTVISITOR_HPP
# define YAPOG_IWRITERCONSTVISITOR_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  class XmlWriter;
  class DebugLogger;

  struct YAPOG_LIB IWriterConstVisitor
  {
    public:

      virtual ~IWriterConstVisitor () {};

      virtual void Visit (const XmlWriter& visitable) = 0;
      virtual void Visit (const DebugLogger& visitable) = 0;
  };
} // namespace yap

#endif // YAPOG_IWRITERCONSTVISITOR_HPP
