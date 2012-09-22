#ifndef YAPOG_PROGRESSBARWIDGET_HPP
# define YAPOG_PROGRESSBARWIDGET_HPP

# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/Graphics/Texture.hpp"
# include "YAPOG/Graphics/Gui/TextureManager.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Collection/Array.hpp"

namespace yap
{
  class YAPOG_LIB ProgressBarWidget : public BaseWidget
  {
    DISALLOW_COPY(ProgressBarWidget);

  public:

    ProgressBarWidget ();

    virtual ~ProgressBarWidget ();

  };
} // namespace yap

#endif /* YAPOG_PROGRESSBARWIDGET_HPP! */