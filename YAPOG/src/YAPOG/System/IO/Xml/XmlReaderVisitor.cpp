#include "YAPOG/System/IO/Xml/XmlReaderVisitor.hpp"

namespace yap
{
  XmlReaderVisitor::XmlReaderVisitor ()
  {
  }

  XmlReaderVisitor::~XmlReaderVisitor ()
  {
  }

  void XmlReaderVisitor::Visit (XmlReader& visitable)
  {
    HandleVisit (visitable);
  }
} // namespace yap
