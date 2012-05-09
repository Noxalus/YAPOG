#ifndef YAPOG_IREADERCONSTVISITOR_HPP
# define YAPOG_IREADERCONSTVISITOR_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  class XmlReader;
  class Packet;

  struct YAPOG_LIB IReaderConstVisitor
  {
      virtual ~IReaderConstVisitor () {}

      virtual void Visit (const XmlReader& visitable) = 0;
      virtual void Visit (const Packet& visitable) = 0;
  };
} // namespace yap

#endif // YAPOG_IREADERCONSTVISITOR_HPP
