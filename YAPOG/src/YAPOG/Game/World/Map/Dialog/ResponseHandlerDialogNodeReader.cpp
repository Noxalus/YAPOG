#include "YAPOG/Game/World/Map/Dialog/ResponseHandlerDialogNodeReader.hpp"
#include "YAPOG/Game/World/Map/Dialog/ResponseHandlerDialogNode.hpp"
#include "YAPOG/Game/World/Map/Dialog/ResponseHandlerDialogNodeEntry.hpp"
#include "YAPOG/Game/World/Map/Dialog/DialogMessage.hpp"
#include "YAPOG/Game/World/Map/Dialog/DialogResponse.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReaderCollection.hpp"
#include "YAPOG/Game/IGameAction.hpp"
#include "YAPOG/Game/IGameRequirement.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"

namespace yap
{
  ResponseHandlerDialogNodeReader::ResponseHandlerDialogNodeReader (
    ResponseHandlerDialogNode& responseHandlerDialogNode,
    const String& xmlRootNodeName)
    : xmlRootNodeName_ (xmlRootNodeName)
    , responseHandlerDialogNode_ (responseHandlerDialogNode)
  {
  }

  ResponseHandlerDialogNodeReader::~ResponseHandlerDialogNodeReader ()
  {
  }

  void ResponseHandlerDialogNodeReader::Visit (XmlReader& visitable)
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

      ResponseHandlerDialogNodeEntry* entry =
        new ResponseHandlerDialogNodeEntry (
          requirement,
          action);

      {
        auto messagesReader = entryReader->ChangeRoot ("messages");

        XmlReaderCollection messageReaders;
        messagesReader->ReadNodes ("entry", messageReaders);
        for (const auto& messageReader : messageReaders)
          entry->AddMessage (new DialogMessage (messageReader->ReadString ()));
      }

      {
        auto responsesReader = entryReader->ChangeRoot ("responses");

        XmlReaderCollection responseReaders;
        responsesReader->ReadNodes ("entry", responseReaders);
        for (const auto& responseReader : responseReaders)
        {
          DialogResponse* response = new DialogResponse (
            responseReader->ReadString (
              "response"));

          IDialogNode* nextNode = nullptr;

          if (responseReader->NodeExists ("nextNode"))
          {
            auto nextNodeReader = responseReader->ChangeRoot ("nextNode");

            String nextNodeType = nextNodeReader->ReadString (
              "dialogNodeType");

            nextNode = ObjectFactory::Instance ().Create<IDialogNode> (
              nextNodeType,
              *nextNodeReader,
              nextNodeType);
          }

          entry->AddResponse (response, nextNode);
        }
      }

      responseHandlerDialogNode_.AddEntry (entry);
    }
  }
} // namespace yap
