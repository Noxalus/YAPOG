#ifndef YAPOG_CLIENT_MAPPLAYERINFOPANEL_HPP
# define YAPOG_CLIENT_MAPPLAYERINFOPANEL_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/Game/World/GameWorldWidget.hpp"

namespace yap
{
  class Label;
} // namespace yap

namespace ycl
{
  class Player;

  class MapPlayerInfoPanel : public yap::GameWorldWidget
  {
      DISALLOW_COPY(MapPlayerInfoPanel);

    public:

      MapPlayerInfoPanel ();

      virtual ~MapPlayerInfoPanel ();

      void Init (Player& player);

    protected:

      virtual void HandleOnWorldCameraChanged (
        const yap::ICamera& worldCamera);

    private:

      void UpdateLabel (const yap::Vector2& position);

      Player* player_;

      /// @warning [TMP]
      yap::Label* playerNameLabel_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_MAPPLAYERINFOPANEL_HPP
