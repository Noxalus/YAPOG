#ifndef YAPOG_STATICWORLDOBJECTREADER_HPP
# define YAPOG_STATICWORLDOBJECTREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/WorldObjectReader.hpp"

namespace yap
{
  class StaticWorldObject;

  class YAPOG_LIB StaticWorldObjectReader : public WorldObjectReader
  {
      DISALLOW_COPY(StaticWorldObjectReader);

    public:

      virtual ~StaticWorldObjectReader ();

    protected:

      StaticWorldObjectReader (
        StaticWorldObject& staticWorldObject,
        const String& xmlRootNodeName);

    private:

      StaticWorldObject& staticWorldObject_;
  };
} // namespace yap

#endif // YAPOG_STATICWORLDOBJECTREADER_HPP
