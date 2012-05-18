#include "YAPOG/System/IO/BaseWriterVisitor.hpp"

namespace yap
{
  BaseWriterVisitor::BaseWriterVisitor ()
  {
  }

  BaseWriterVisitor::~BaseWriterVisitor ()
  {
  }

  void BaseWriterVisitor::Visit (XmlWriter& visitable)
  {
  }

  void BaseWriterVisitor::Visit (DebugLogger& visitable)
  {
  }

  void BaseWriterVisitor::Visit (DatabaseLogger& visitable)
  {
  }

  void BaseWriterVisitor::Visit (Packet& visitable)
  {
  }

  void BaseWriterVisitor::Visit (DatabaseStream& visitable)
  {
  }
} // namespace yap
