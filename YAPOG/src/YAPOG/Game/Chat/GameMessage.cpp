#include "YAPOG/Game/Chat/GameMessage.hpp"

namespace yap
{
  GameMessage::GameMessage ()
    : content_ ()
    , senderName_ ()
  {
  }

  GameMessage::~GameMessage ()
  {
  }

  const String& GameMessage::GetContent () const
  {
    return content_;
  }

  const String& GameMessage::GetSenderName () const
  {
    return senderName_;
  }

  void GameMessage::SetContent (const String& content)
  {
    content_ = content;
  }

  void GameMessage::SetSenderName (const String& senderName)
  {
    senderName_ = senderName;
  }
} // namespace yap
