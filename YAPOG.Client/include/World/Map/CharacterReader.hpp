#ifndef YAPOG_CLIENT_CHARACTERREADER_HPP
# define YAPOG_CLIENT_CHARACTERREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/CharacterReader.hpp"

class Character;

class CharacterReader : public yap::CharacterReader
{
    DISALLOW_COPY(CharacterReader);

  public:

    virtual ~CharacterReader ();

  protected:

    CharacterReader (
      Character& character,
      const yap::String& xmlRootNodeName);

  private:

    Character& character_;
};

#endif // YAPOG_CLIENT_CHARACTERREADER_HPP
