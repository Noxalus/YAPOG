#include "YAPOG/Game/World/Map/MapXmlLoader.hpp"

namespace yap
{
  const Path MapXmlLoader::DEFAULT_ROOT_PATH_NAME = Path ("Map");
  const String MapXmlLoader::DEFAULT_ROOT_NODE_NAME = "Map";

  MapXmlLoader::MapXmlLoader (const Path& contentPathRootName)
    : XmlLoader (contentPathRootName + DEFAULT_ROOT_PATH_NAME,
                 DEFAULT_ROOT_NODE_NAME)
  {
  }

  MapXmlLoader::~MapXmlLoader ()
  {
  }

  Map* MapXmlLoader::HandleLoad (const ID& id)
  {

  }
} // namespace yap
