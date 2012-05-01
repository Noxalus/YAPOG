#ifndef YAPOG_CHARACTERREADER_HPP
# define YAPOG_CHARACTERREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/DynamicWorldObjectReader.hpp"

namespace yap
{
  class Character;

  class YAPOG_LIB CharacterReader : public DynamicWorldObjectReader
  {
      DISALLOW_COPY(CharacterReader);

    public:

      virtual ~CharacterReader ();

    protected:

      CharacterReader (
        Character& character,
        const String& xmlRootNodeName);

    private:

      Character& character_;
  };
} // namespace yap

#endif // YAPOG_CHARACTERREADER_HPP
