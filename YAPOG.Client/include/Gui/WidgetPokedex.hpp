#ifndef YAPOG_CLIENT_WIDGETPOKEDEX_HPP
# define YAPOG_CLIENT_WIDGETPOKEDEX_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"

namespace yap
{
  class Pokedex;
}

namespace ycl
{
  class WidgetPokedex : public yap::BaseWidget
  {
      DISALLOW_COPY(WidgetPokedex);

    public:
      WidgetPokedex ();
      void Init ();
      virtual ~WidgetPokedex();

    private:
      yap::Pokedex* pokedex_
  };
} // namespace ycl

#endif // YAPOG_CLIENT_WIDGETPOKEDEX_HPP