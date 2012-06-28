#ifndef YAPOG_MAPAREAREADER_HPP
# define YAPOG_MAPAREAREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/DynamicWorldObjectReader.hpp"

namespace yap
{
  class MapArea;

  class YAPOG_LIB MapAreaReader : public DynamicWorldObjectReader
  {
    DISALLOW_COPY(MapAreaReader);

  public:

    virtual ~MapAreaReader ();

  protected:

    MapAreaReader (MapArea& mapArea, const String& xmlRootNodeName);

  private:

    MapArea& mapArea_;
  };
} // namespace yap

#endif // YAPOG_MAPAREAREADER_HPP
