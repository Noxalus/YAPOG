#ifndef YAPOG_IWIDGET_HPP
# define YAPOG_IWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/ISpatial.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"
# include "YAPOG/Graphics/Gui/IEventHandler.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/System/IntTypes.hpp"

namespace yap
{
  class Padding;
  class BackgroundWidget;
  class BorderWidget;
  /// @brief Base element of the graphical user interface.
  struct YAPOG_LIB IWidget :
    public ISpatial,
    public IDrawable,
    public IEventHandler,
    public IUpdateable
  {
    virtual ~IWidget () {}

    virtual void AddDrawable (IDrawable& drawable) = 0;
    virtual void AddChild (IWidget& child) = 0;
    virtual IWidget& GetRoot () const = 0;
    virtual void SetParent (IWidget& parent) = 0;
    virtual void SetPadding (Padding* padding) = 0;
    virtual void SetBackground (BackgroundWidget& background) = 0;
    virtual void SetBorder  (BorderWidget& border, uint width) = 0;
    virtual void Refresh () = 0;
    virtual bool IsFocusable () const = 0;
    virtual void SetFocused (bool state) = 0;
    virtual void SetEnable (bool enable) = 0;
    virtual void Open () = 0;
    virtual void Close () = 0;
  };
} // namespace yap

#endif // YAPOG_IWIDGET_HPP
