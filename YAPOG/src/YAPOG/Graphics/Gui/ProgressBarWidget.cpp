#include "YAPOG/Graphics/Gui/ProgressBarWidget.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"

namespace yap
{
  ProgressBarWidget::ProgressBarWidget ()
    : BaseWidget ()
    , variance_ (0)
    , previousValue_ (0)
    , timer_ ()
    , barContent_ (nullptr)
    , mainLayout_ (nullptr)
  {
  }

  ProgressBarWidget::~ProgressBarWidget ()
  {
  }

  void ProgressBarWidget::HandleUpdate (const yap::Time& dt)
  {
    yap::BaseWidget::HandleUpdate (dt);

    if (variance_ != 0 && 
      timer_.GetCurrentTime ().GetValue () >= 0.02f)
    {
      if (variance_ > 0)
        variance_--;
      else
        variance_++;

      RefreshWidget ();
      timer_.Reset ();
    }

    timer_.Update (dt);
  }

} //namespace yap
