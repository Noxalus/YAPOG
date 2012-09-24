#include "YAPOG/Game/World/Map/Dialog/DialogMessage.hpp"

namespace yap
{
  DialogMessage::DialogMessage (const String& content)
    : content_ (content)
  {
  }

  DialogMessage::~DialogMessage ()
  {
  }

  DialogMessage::DialogMessage (const DialogMessage& copy)
    : content_ (copy.content_)
  {
  }

  DialogMessage* DialogMessage::Clone () const
  {
    return new DialogMessage (*this);
  }

  const String& DialogMessage::GetContent () const
  {
    return content_;
  }
} // namespace yap
