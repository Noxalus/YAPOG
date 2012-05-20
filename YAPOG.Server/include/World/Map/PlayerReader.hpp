#ifndef YAPOG_SERVER_PLAYERREADER_HPP
# define YAPOG_SERVER_PLAYERREADER_HPP

# include "YAPOG/Macros.hpp"
# include "World/Map/CharacterReader.hpp"

namespace yse
{
  class Player;

  class PlayerReader : public CharacterReader
  {
      DISALLOW_COPY(PlayerReader);

    public:

      PlayerReader (
        Player& character,
        const yap::String& xmlRootNodeName);
      virtual ~PlayerReader ();

      virtual void Visit (yap::XmlReader& visitable);

    private:

      Player& player_;
  };
} // namespace yse

#endif // YAPOG_SERVER_PLAYERREADER_HPP
