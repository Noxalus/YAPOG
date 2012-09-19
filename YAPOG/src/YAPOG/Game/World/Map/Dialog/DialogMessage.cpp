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

  const String& DialogMessage::GetContent () const
  {
    return content_;
  }
} // namespace yap
