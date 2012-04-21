#ifndef YAPOG_MAPXMLLOADER_HPP
# define YAPOG_MAPXMLLOADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Factory/XmlLoader.hpp"
# include "YAPOG/Game/World/Map/Map.hpp"

namespace yap
{
  class MapXmlLoader : public XmlLoader<Map>
  {
    public:

      MapXmlLoader (const Path& contentPathRoot);
      virtual ~MapXmlLoader ();

    private:

      virtual Map* HandleLoad (const ID& id);

      static const Path DEFAULT_ROOT_PATH;
      static const String DEFAULT_ROOT_NODE_NAME;
  };
} // namespace yap

#endif // YAPOG_MAPXMLLOADER_HPP
