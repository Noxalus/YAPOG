#ifndef YAPOG_POKEMONINFOREADER_HPP
# define YAPOG_POKEMONINFOREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/IReaderVisitor.hpp"
# include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
# include "YAPOG/System/IO/Xml/XmlHelper.hpp"

namespace yap
{
  class YAPOG_LIB PokemonInfoReader : public IReaderVisitor
  {
    DISALLOW_COPY(PokemonInfoReader);

  public:
    PokemonInfoReader (PokemonInfo& pokeInfo);
    PokemonInfoReader (PokemonInfo& map, const String& xmlRootNodeName);
    virtual ~PokemonInfoReader ();

    virtual void Visit (XmlReader& visitable);
  private:
    PokemonInfo& pokeInfo_;
    String xmlRootNodeName_;

    static const String DEFAULT_XML_ROOT_NODE_NAME;
    static const String DEFAULT_XML_ID_NODE_NAME;
    static const String DEFAULT_XML_NAME_NODE_NAME;
    static const String DEFAULT_XML_DESCRIPTION_NODE_NAME;
    static const String DEFAULT_XML_SPECIES_NODE_NAME;
    static const String DEFAULT_XML_HEIGHT_NODE_NAME;
    static const String DEFAULT_XML_WEIGHT_NODE_NAME;
    static const String DEFAULT_XML_RARITY_NODE_NAME;
    static const String DEFAULT_XML_EXPERIENCE_NODE_NAME;
    static const String DEFAULT_XML_BASE_STATS_NODE_NAME;
    static const String DEFAULT_XML_HP_NODE_NAME;
    static const String DEFAULT_XML_ATTACK_NODE_NAME;
    static const String DEFAULT_XML_DEFENSE_NODE_NAME;
    static const String DEFAULT_XML_SPECIAL_ATTACK_NODE_NAME;
    static const String DEFAULT_XML_SPECIAL_DEFENSE_NODE_NAME;
    static const String DEFAULT_XML_SPEED_NODE_NAME;
  };
} // namespace yap

#endif // YAPOG_POKEMONINFOREADER_HPP

