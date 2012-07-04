#ifndef YAPOG_CLIENT_CONFIGURATION_READER_HPP
# define YAPOG_CLIENT_CONFIGURATION_READER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Configuration/ConfigurationReader.hpp"

namespace ycl
{
  class GameData;

  class ConfigurationReader : public yap::ConfigurationReader
  {
      DISALLOW_COPY(ConfigurationReader);

    public:

      ConfigurationReader (
        GameData& gameData,
        const yap::String& xmlRootNodeName);

      virtual ~ConfigurationReader ();

    protected:

      virtual void HandleVisitXmlReader (yap::XmlReader& visitable);

    private:

      GameData& gameData_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_CONFIGURATION_READER_HPP
