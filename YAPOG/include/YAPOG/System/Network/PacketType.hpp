#ifndef YAPOG_PACKETTYPE_HPP
# define YAPOG_PACKETTYPE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"

namespace yap
{
  enum class YAPOG_LIB PacketType : Int16
  {
    // reserved
    None = 0,

    // from client to server
    ClientRequestLogin,
    ClientInfoDeconnection,

    ClientRequestStartInfo,

    ClientInfoApplyForce,

    ClientInfoGameInput,

    // from server to client
    ServerInfoLoginValidation,
    ServerInfoLoginError,

    ServerInfoPrimaryData,

    ServerInfoChangeMap,

    ServerInfoSetUserPlayer,

    ServerInfoUpdateObjectState,
    ServerInfoObjectMoveInfo,

    ServerInfoAddObject,
    ServerInfoRemoveObject
  };
} // namespace yap

#endif // YAPOG_PACKETTYPE_HPP
