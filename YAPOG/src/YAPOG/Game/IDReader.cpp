#include "YAPOG/Game/IDReader.hpp"
#include "YAPOG/Game/ID.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"

namespace yap
{
  IDReader::IDReader (ID& id)
    : id_ (id)
  {
  }

  IDReader::~IDReader ()
  {
  }

  void IDReader::Visit (XmlReader& visitable)
  {
    id_.ChangeValue (visitable.ReadUInt64 ("ID"));
  }
} // namespace yap
