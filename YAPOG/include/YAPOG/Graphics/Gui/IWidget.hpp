#ifndef YAPOG_IWIDGET_HPP
# define YAPOG_IWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/ISpatial.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"
# include "YAPOG/Graphics/Gui/IEventHandler.hpp"
# include "YAPOG/Game/IUpdateable.hpp"

namespace yap
{
  /// @brief Base element of the graphical user interface.
  struct YAPOG_LIB IWidget : public ISpatial,
                             public IDrawable,
                             public IEventHandler,
                             public IUpdateable
  {
      virtual ~IWidget () {}
  };
} // namespace yap

#endif // YAPOG_IWIDGET_HPP
