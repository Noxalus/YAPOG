#ifndef YAPOG_SERVER_CLIENTSESSION_HPP
# define YAPOG_SERVER_CLIENTSESSION_HPP

# include <SFML/Network/SocketSelector.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Network/IPacketHandler.hpp"
# include "YAPOG/System/Network/PacketHandler.hpp"
# include "YAPOG/System/Network/ClientSocket.hpp"
# include "YAPOG/System/Network/NetworkHandler.hpp"
# include "YAPOG/System/Event/Event.hpp"
# include "YAPOG/Game/Factory/ObjectFactory.hpp"

# include "Server/User.hpp"

namespace yap
{
  class DatabaseManager;
} // namespace yap

namespace yse
{
  class ClientSession : public yap::IPacketHandler
  {
    DISALLOW_COPY(ClientSession);

  public:

    ClientSession ();
    virtual ~ClientSession ();

    void Init ();

    void Refresh ();

    void HandleReception ();

    User& GetUser ();

    yap::ClientSocket& GetSocket ();

    void SetDatabaseManager (yap::DatabaseManager* databaseManager);

    /// @name IPacketHandler members.
    /// @{
    virtual bool HandlePacket (yap::IPacket& packet);
    virtual bool SendPacket (yap::IPacket& packet);

    virtual void AddRelay (yap::IPacketHandler* relay);
    virtual void RemoveRelay (yap::IPacketHandler* relay);
    virtual void SetParent (yap::IPacketHandler* parent);
    /// @}

    yap::Event<
      const ClientSession&,
      const yap::EmptyEventArgs&> OnDisconnected;

  private:

    bool IsConnected () const;

    void Disconnect ();

    void HandleClientRequestLogin (yap::IPacket& packet);
    void HandleClientRequestRegistration (yap::IPacket& packet);
    void HandleClientInfoDeconnection (yap::IPacket& packet);

    void SendObjectFactoryTypes (
      yap::IPacket& packet,
      const yap::ObjectFactory& objectFactory);

    bool isConnected_;

    yap::PacketHandler packetHandler_;

    yap::ClientSocket socket_;
    yap::NetworkHandler networkHandler_;

    User user_;
    yap::DatabaseManager* databaseManager_;
  };
} // namespace yap

#endif // YAPOG_SERVER_CLIENTSESSION_HPP
