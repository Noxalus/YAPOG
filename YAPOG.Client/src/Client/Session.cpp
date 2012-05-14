#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"

#include "Client/Session.hpp"

namespace ycl
{
  Session::Session ()
    : packetHandler_ ()
    , socket_ ()
    , networkHandler_ (socket_)
  {
  }

  Session::~Session ()
  {
  }

  Session& Session::Instance ()
  {
    static Session instance;

    return instance;
  }

  void Session::Refresh ()
  {
    networkHandler_.Refresh ();

    while (!networkHandler_.IsEmpty ())
      if (!HandlePacket (*networkHandler_.GetPacket ()))
        YAPOG_THROW("Wrong packet received.");
  }

  bool Session::HandlePacket (yap::IPacket& packet)
  {
    return packetHandler_.HandlePacket (packet);
  }

  bool Session::SendPacket (yap::IPacket& packet)
  {
    return socket_.Send (packet);
  }

  void Session::AddRelay (yap::IPacketHandler* relay)
  {
    packetHandler_.AddRelay (relay);
  }

  void Session::SetParent (yap::IPacketHandler* parent)
  {
    packetHandler_.SetParent (parent);
  }
} // namespace ycl
