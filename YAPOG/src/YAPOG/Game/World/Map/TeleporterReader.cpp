#include "YAPOG/Game/World/Map/TeleporterReader.hpp"
#include "YAPOG/Game/World/Map/Teleporter.hpp"

namespace yap
{
  TeleporterReader::TeleporterReader (
    Teleporter& teleporter,
    const String& xmlRootNodeName)
    : DynamicWorldObjectReader (teleporter, xmlRootNodeName)
    , teleporter_ (teleporter)
  {
  }

  TeleporterReader::~TeleporterReader ()
  {
  }
} // namespace yap
