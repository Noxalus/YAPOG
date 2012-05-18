#include "YAPOG/System/IO/BaseWriterConstVisitor.hpp"

namespace yap
{
  BaseWriterConstVisitor::BaseWriterConstVisitor ()
  {
  }

  BaseWriterConstVisitor::~BaseWriterConstVisitor ()
  {
  }

  void BaseWriterConstVisitor::Visit (const XmlWriter& visitable)
  {
  }

  void BaseWriterConstVisitor::Visit (const DebugLogger& visitable)
  {
  }

  void BaseWriterConstVisitor::Visit (const DatabaseLogger& visitable)
  {
  }

  void BaseWriterConstVisitor::Visit (const Packet& visitable)
  {
  }

  void BaseWriterConstVisitor::Visit (const DatabaseStream& visitable)
  {
  }
} // namespace yap
