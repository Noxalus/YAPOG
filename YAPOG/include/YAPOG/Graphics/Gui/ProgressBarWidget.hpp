#ifndef YAPOG_PROGRESSBARWIDGET_HPP
# define YAPOG_PROGRESSBARWIDGET_HPP

# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/Graphics/Texture.hpp"
# include "YAPOG/Graphics/Gui/TextureManager.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/System/Time/UpdateableTimer.hpp"

namespace yap
{
  class PictureBox;
  class HorizontalLayout;

  class YAPOG_LIB ProgressBarWidget : public BaseWidget
  {
    DISALLOW_COPY(ProgressBarWidget);

  public:

    ProgressBarWidget ();

    virtual ~ProgressBarWidget ();

    virtual void Init () = 0;
    virtual void UpdateProgressBar () = 0;

  protected:
    virtual void RealUpdate () = 0;
    virtual void HandleUpdate (const yap::Time& dt);

    int variance_;
    yap::UInt16 previousValue_;
    yap::UpdateableTimer timer_;
    yap::PictureBox* barContent_;
    yap::HorizontalLayout* mainLayout_;
  };
} // namespace yap

#endif /* YAPOG_PROGRESSBARWIDGET_HPP! */