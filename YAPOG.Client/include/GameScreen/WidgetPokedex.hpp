#ifndef YAPOG_CLIENT_WIDGETPOKEDEX_HPP
# define YAPOG_CLIENT_WIDGETPOKEDEX_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/Menu.hpp"

namespace ycl
{
  class WidgetPokedex
  {
      DISALLOW_COPY(WidgetPokedex);

    public:
      WidgetPokedex ();
      void Init ();
      virtual ~WidgetPokedex();

    private:
  };
} // namespace ycl

#endif // YAPOG_CLIENT_WIDGETPOKEDEX_HPP