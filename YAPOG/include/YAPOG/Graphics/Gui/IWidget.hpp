#ifndef YAPOG_IWIDGET_HPP
# define YAPOG_IWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"
# include "YAPOG/Graphics/Gui/IEventHandler.hpp"
# include "YAPOG/Game/IUpdatable.hpp"

namespace yap
{
  /// @brief Base element of the graphical user interface.
  struct YAPOG_LIB IWidget : public IDrawable,
                             public IEventHandler,
                             public IUpdatable
  {
      virtual ~IWidget () {}
  };
} // namespace yap

#endif // YAPOG_IWIDGET_HPP
