#ifndef YAPOG_PACKETTYPE_HPP
# define YAPOG_PACKETTYPE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"

namespace yap
{
  enum class YAPOG_LIB PacketType : Int16
  {
    None = 0,

    // from client to server
    ClientRequestLogin,
    ClientInfoDeconnection,

    ClientRequestStartInfo,

    ClientInfoStartMove,
    ClientInfoEndMove,

    // from server to client
    ServerInfoLoginValidation,

    ServerInfoStartInfo,

    ServerInfoObjectMove
  };
} // namespace yap

#endif // YAPOG_PACKETTYPE_HPP
