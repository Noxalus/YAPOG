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
    ClientRequestRegistration,
    ClientInfoDeconnection,

    ClientRequestStartInfo,

    ClientInfoApplyForce,

    ClientInfoGameInput,

    ClientInfoGameMessage,

    // from server to client
    ServerInfoLoginValidation,
    ServerInfoRegistrationValidation,
    ServerInfoLoginError,
    ServerInfoRegistrationError,

    ServerInfoPrimaryData,

    ServerInfoChangeMap,

    ServerInfoSetUserPlayer,

    ServerInfoUpdateObjectState,
    ServerInfoObjectMoveInfo,

    ServerInfoAddObject,
    ServerInfoRemoveObject,

    ServerInfoGameMessage,

    ServerInfoTriggerBattle,

    ServerInfoPokemonTeam,

    ServerInfoChangeMoney
  };
} // namespace yap

#endif // YAPOG_PACKETTYPE_HPP
