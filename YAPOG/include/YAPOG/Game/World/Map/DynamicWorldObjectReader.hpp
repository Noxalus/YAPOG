#ifndef YAPOG_DYNAMICWORLDOBJECTREADER_HPP
# define YAPOG_DYNAMICWORLDOBJECTREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/WorldObjectReader.hpp"

namespace yap
{
  class DynamicWorldObject;

  class DynamicWorldObjectReader : public WorldObjectReader
  {
      DISALLOW_COPY(DynamicWorldObjectReader);

    public:

      virtual ~DynamicWorldObjectReader ();

    protected:

      DynamicWorldObjectReader (
        DynamicWorldObject& dynamicWorldObject,
        const String& xmlRootNodeName);

    private:

      DynamicWorldObject& dynamicWorldObject_;
  };
} // namespace yap

#endif // YAPOG_DYNAMICWORLDOBJECTREADER_HPP
