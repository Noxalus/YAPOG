#ifndef YAPOG_CLIENT_UPDATESCREEN_HPP
# define YAPOG_CLIENT_UPDATESCREEN_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/System/Hash/FileChecker.hpp"
# include "YAPOG/Graphics/Gui/Label.hpp"
# include "YAPOG/Graphics/Gui/PictureBox.hpp"
# include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
# include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"

# include <boost/filesystem.hpp>
# include "GameScreen/BaseScreen.hpp"

namespace ycl
{
  class UpdateScreen : public BaseScreen
  {
      DISALLOW_COPY(UpdateScreen);

    public:

      UpdateScreen ();
      virtual ~UpdateScreen ();

    protected:

      virtual void HandleInit ();

      virtual void HandleActivate ();

      virtual void HandleRun (
        const yap::Time& dt,
        yap::IDrawingContext& context);

    private:
      void Update ();
      void UpdateContentSize (int value);

      yap::UInt16             lastlength_;
      yap::FileChecker*       fc_;
      yap::Label              fileName_;
      yap::Label              filePercentage_;
      yap::Label              fileDownloaded_;
      yap::Label              totalFile_;
      yap::PictureBox*        backgroundbox_;
      yap::PictureBox*        foregroundbox_;
      yap::HorizontalLayout*  firstLayout_;
      yap::HorizontalLayout*  secondLayout_;
      yap::VerticalLayout*    bigLayout_;

      static const yap::ScreenType DEFAULT_NAME;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_UPDATESCREEN_HPP
