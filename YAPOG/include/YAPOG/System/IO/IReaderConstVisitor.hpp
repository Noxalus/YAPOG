#ifndef YAPOG_IREADERCONSTVISITOR_HPP
# define YAPOG_IREADERCONSTVISITOR_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  struct IPacket;

  class XmlReader;
  class DatabaseStream;

  struct YAPOG_LIB IReaderConstVisitor
  {
      virtual ~IReaderConstVisitor () {}

      virtual void Visit (const XmlReader& visitable) = 0;
      virtual void Visit (const IPacket& visitable) = 0;
      virtual void Visit (const DatabaseStream& visitable) = 0;
  };
} // namespace yap

#endif // YAPOG_IREADERCONSTVISITOR_HPP
