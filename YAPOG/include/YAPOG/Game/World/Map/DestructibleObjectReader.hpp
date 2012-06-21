#ifndef YAPOG_DESTRUCTIBLEOBJECTREADER_HPP
# define YAPOG_DESTRUCTIBLEOBJECTREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/DynamicWorldObjectReader.hpp"

namespace yap
{
  class DestructibleObject;

  class YAPOG_LIB DestructibleObjectReader : public DynamicWorldObjectReader
  {
      DISALLOW_COPY(DestructibleObjectReader);

    public:

      DestructibleObjectReader (
        DestructibleObject& destructibleObject,
        const String& xmlRootNodeName);
      virtual ~DestructibleObjectReader ();

      virtual void Visit (XmlReader& visitable);

    private:

      DestructibleObject& destructibleObject_;
  };
} // namespace yap

#endif // YAPOG_DESTRUCTIBLEOBJECTREADER_HPP
