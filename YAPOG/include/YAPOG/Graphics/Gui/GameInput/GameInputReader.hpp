#ifndef YAPOG_GAMEINPUTREADER_HPP
# define YAPOG_GAMEINPUTREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/Xml/XmlReaderVisitor.hpp"

namespace yap
{
  class GameInputReader : public XmlReaderVisitor
  {
      DISALLOW_COPY(GameInputReader);

    public:

      GameInputReader ();
      virtual ~GameInputReader ();

    private:

      virtual void HandleVisit (XmlReader& visitable);
  };
} // namespace yap

#endif // YAPOG_GAMEINPUTREADER_HPP
