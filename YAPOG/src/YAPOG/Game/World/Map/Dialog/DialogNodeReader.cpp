#include "YAPOG/Game/World/Map/Dialog/DialogNodeReader.hpp"
#include "YAPOG/Game/World/Map/Dialog/DialogNode.hpp"
#include "YAPOG/Game/World/Map/Dialog/DialogNodeEntry.hpp"
#include "YAPOG/Game/World/Map/Dialog/DialogMessage.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReaderCollection.hpp"
#include "YAPOG/Game/IGameAction.hpp"
#include "YAPOG/Game/IGameRequirement.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"

namespace yap
{
  DialogNodeReader::DialogNodeReader (
    DialogNode& dialogNode,
    const String& xmlRootNodeName)
    : xmlRootNodeName_ (xmlRootNodeName)
    , dialogNode_ (dialogNode)
  {
  }

  DialogNodeReader::~DialogNodeReader ()
  {
  }

  void DialogNodeReader::Visit (XmlReader& visitable)
  {
    BaseReaderVisitor::Visit (visitable);

    auto reader = visitable.ChangeRoot (xmlRootNodeName_);

    XmlReaderCollection entryReaders;
    reader->ReadNodes ("entry", entryReaders);
    for (const auto& entryReader : entryReaders)
    {
      IGameRequirement* requirement = nullptr;

      if (entryReader->NodeExists ("requirement"))
      {
      }

      IGameAction* action = nullptr;

      if (entryReader->NodeExists ("action"))
      {
      }

      IDialogNode* nextNode = nullptr;

      if (entryReader->NodeExists ("nextNode"))
      {
        auto nextNodeReader = entryReader->ChangeRoot ("nextNode");

        String nextNodeType = nextNodeReader->ReadString ("dialogNodeType");

        nextNode = ObjectFactory::Instance ().Create<IDialogNode> (
          nextNodeType,
          *nextNodeReader,
          nextNodeType);
      }

      DialogNodeEntry* entry = new DialogNodeEntry (
        requirement,
        action,
        nextNode);

      {
        auto messagesReader = entryReader->ChangeRoot ("messages");

        XmlReaderCollection messageReaders;
        messagesReader->ReadNodes ("entry", messageReaders);
        for (const auto& messageReader : messageReaders)
          entry->AddMessage (new DialogMessage (messageReader->ReadString ()));
      }

      dialogNode_.AddEntry (entry);
    }
  }
} // namespace yap
