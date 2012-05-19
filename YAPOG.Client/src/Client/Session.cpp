#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/System/Network/Packet.hpp"

#include "Client/Session.hpp"

#include "YAPOG/System/IO/Log/DebugLogger.hpp"
namespace ycl
{
  const yap::String Session::DEFAULT_REMOTE_IP = "localhost";
  const yap::Int16 Session::DEFAULT_REMOTE_PORT = 8008;

  const yap::Time Session::DEFAULT_DATA_WAITING_DELAY = yap::Time (2.0f);

  Session::Session ()
    : packetHandler_ ()
    , receptionThread_ ([&] () { HandleReception (); })
    , receptionIsActive_ (false)
    , socket_ ()
    , networkHandler_ (socket_)
    , user_ ()
  {
    ADD_HANDLER(
      ServerInfoLoginValidation,
      Session::HandleServerInfoLoginValidation);
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
    while (!networkHandler_.IsEmpty ())
    {
      yap::PacketPtrType packet (networkHandler_.GetPacket ());
      yap::DebugLogger::Instance ().LogLine (
        "Packet: " +
        yap::StringHelper::ToString (static_cast<int> (packet->GetType ())));
      if (!HandlePacket (*packet))
        YAPOG_THROW("Wrong packet received.");
    }
  }

  void Session::Login (const yap::String& login)
  {
    if (!Connect ())
      YAPOG_THROW("Failed to connect to the serveur `"
                  + DEFAULT_REMOTE_IP
                  + "'.");

    /// @todo login request
    yap::Packet packet;
    packet.CreateFromType (yap::PacketType::ClientRequestLogin);

    SendPacket (packet);
  }

  User& Session::GetUser ()
  {
    return user_;
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

  bool Session::Connect ()
  {
    if (!socket_.Connect (DEFAULT_REMOTE_IP, DEFAULT_REMOTE_PORT))
      return false;

    AddRelay (&user_);

    receptionIsActive_ = true;
    receptionThread_.Launch ();

    return true;
  }

  void Session::Disconnect ()
  {
    yap::Packet packet;
    packet.CreateFromType (yap::PacketType::ClientInfoDeconnection);
    SendPacket (packet);

    socket_.Disconnect ();

    receptionIsActive_ = false;
  }

  void Session::HandleReception ()
  {
    while (receptionIsActive_)
      networkHandler_.Refresh ();
  }

  void Session::HandleServerInfoLoginValidation (yap::IPacket& packet)
  {
    yap::Packet tmppacket;
    tmppacket.CreateFromType (yap::PacketType::None);
    SendPacket (tmppacket);
  }
} // namespace ycl
