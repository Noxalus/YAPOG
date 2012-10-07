#include "YAPOG/Game/World/Map/Dialog/DialogResponse.hpp"

namespace yap
{
  DialogResponse::DialogResponse (const String& messageContent)
    : messageContent_ (messageContent)
  {
  }

  DialogResponse::~DialogResponse ()
  {
  }

  DialogResponse::DialogResponse (const DialogResponse& copy)
    : messageContent_ (copy.messageContent_)
  {
  }

  DialogResponse* DialogResponse::Clone () const
  {
    return new DialogResponse (*this);
  }

  const String& DialogResponse::GetMessageContent () const
  {
    return messageContent_;
  }
} // namespace yap
