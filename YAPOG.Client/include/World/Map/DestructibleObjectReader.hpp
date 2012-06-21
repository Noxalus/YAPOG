#ifndef YAPOG_CLIENT_DESTRUCTIBLEOBJECTREADER_HPP
# define YAPOG_CLIENT_DESTRUCTIBLEOBJECTREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/DestructibleObjectReader.hpp"

namespace ycl
{
  class DestructibleObject;

  class DestructibleObjectReader : public yap::DestructibleObjectReader
  {
      DISALLOW_COPY(DestructibleObjectReader);

    public:

      DestructibleObjectReader (
        DestructibleObject& destructibleObject,
        const yap::String& xmlRootNodeName);
      virtual ~DestructibleObjectReader ();

      virtual void Visit (yap::XmlReader& visitable);

    private:

      static const yap::String DEFAULT_XML_SPRITE_TYPE_NODE_NAME;

      DestructibleObject& destructibleObject_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_DESTRUCTIBLEOBJECTREADER_HPP
