#ifndef YAPOG_XMLMAPLOADER_HPP
# define YAPOG_XMLMAPLOADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/XmlLoader.hpp"
# include "YAPOG/Game/World/Map/Map.hpp"
# include "YAPOG/System/Path.hpp"

namespace yap
{
  class MapXmlLoader : public XmlLoader<Map>
  {
    public:

      MapXmlLoader (const Path& contentPathRootName);

    private:

      virtual void HandleLoad (const ID& id);

      static const Path DEFAULT_ROOT_PATH_NAME;
      static const String DEFAULT_ROOT_NODE_NAME;
  };
} // namespace yap

#endif // YAPOG_XMLMAPLOADER_HPP
