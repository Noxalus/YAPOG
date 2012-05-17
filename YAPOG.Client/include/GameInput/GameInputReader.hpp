#ifndef YAPOG_CLIENT_GAMEINPUT_HPP
# define YAPOG_CLIENT_GAMEINPUT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/BaseReaderVisitor.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class GameInputManager;
} // namespace yap

namespace ycl
{
  class GameInputReader : public yap::BaseReaderVisitor
  {
      DISALLOW_COPY(GameInputReader);

    public:

      GameInputReader (
        yap::GameInputManager& gameInputManager,
        const yap::String& xmlRootNodeName);
      virtual ~GameInputReader ();

      virtual void Visit (yap::XmlReader& visitable);

    protected:

      yap::String xmlRootNodeName_;

    private:

      yap::GameInputManager& gameInputManager_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_GAMEINPUT_HPP
