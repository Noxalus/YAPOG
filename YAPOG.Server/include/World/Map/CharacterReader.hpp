#ifndef YAPOG_SERVER_CHARACTERREADER_HPP
# define YAPOG_SERVER_CHARACTERREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/CharacterReader.hpp"

namespace yse
{
  class Character;

  class CharacterReader : public yap::CharacterReader
  {
      DISALLOW_COPY(CharacterReader);

    public:

      virtual ~CharacterReader ();

      virtual void Visit (yap::XmlReader& visitable);

    protected:

      CharacterReader (
        Character& character,
        const yap::String& xmlRootNodeName);

    private:

      Character& character_;
  };
} // namespace yse

#endif // YAPOG_SERVER_CHARACTERREADER_HPP
