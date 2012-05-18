#include "YAPOG/Graphics/Gui/GameInput/GameInputManager.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReaderCollection.hpp"

#include "GameInput/GameInputReader.hpp"

namespace ycl
{
  GameInputReader::GameInputReader (
    yap::GameInputManager& gameInputManager,
    const yap::String& xmlRootNodeName)
    : xmlRootNodeName_ (xmlRootNodeName)
    , gameInputManager_ (gameInputManager)
  {
  }

  GameInputReader::~GameInputReader ()
  {
  }

  void GameInputReader::Visit (yap::XmlReader& visitable)
  {
    auto reader = visitable.ChangeRoot (xmlRootNodeName_);

    yap::XmlReaderCollection entryReaders;
    reader->ReadNodes ("entry", entryReaders);
    for (auto& entryReader : entryReaders)
    {
      /// @todo read inputs entries
    }
  }
} // namespace ycl
