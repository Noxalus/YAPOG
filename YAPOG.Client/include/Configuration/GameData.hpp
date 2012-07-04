#ifndef YAPOG_CLIENT_GAMEDATA_HPP
# define YAPOG_CLIENT_GAMEDATA_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"

namespace ycl
{
  class GameData
  {
      friend class ConfigurationReader;

      DISALLOW_COPY(GameData);

    public:

      static void Init (const yap::String& configurationFileName);

      static const yap::String& RemoteIPAddress ();

    private:

      static GameData& Instance ();

      GameData ();
      ~GameData ();

      static const yap::String DEFAULT_CONFIGURATION_FILE_ROOT_NODE_NAME;
      static const yap::String DEFAULT_REMOVE_IP_ADDRESS;

      yap::String remoteIPAddress_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_GAMEDATA_HPP
