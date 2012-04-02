#include "YAPOG/Game/IDWriter.hpp"
#include "YAPOG/Game/ID.hpp"
#include "YAPOG/System/IO/Xml/XmlWriter.hpp"
#include "YAPOG/System/IO/Log/DebugLogger.hpp"

namespace yap
{
  IDWriter::IDWriter (const ID& id)
    : id_ (id)
  {
  }

  IDWriter::~IDWriter ()
  {
  }

  void IDWriter::Visit (XmlWriter& visitable)
  {
    visitable.Write ("ID", id_.Value ());
  }

  void IDWriter::Visit (DebugLogger& visitable)
  {
    visitable.Write (id_.Value ());
  }
} // namespace yap
