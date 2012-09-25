#ifndef YAPOG_CLIENT_POKEMONINFOWIDGET_HPP
# define YAPOG_CLIENT_POKEMONINFOWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"

# include "Gui/IPokemonSummaryWidget.hpp"

namespace ycl
{
  class Pokemon;

  class PokemonInfoWidget : public yap::BaseWidget
  {
     DISALLOW_COPY(PokemonInfoWidget);
  public:
    PokemonInfoWidget ();
    ~PokemonInfoWidget ();
    
    void Init ();

    void SetPokemon (const Pokemon& pokemon);

    virtual bool IsFocusable () const;

  private:
    const Pokemon* pokemon_;
    yap::UInt8 pageNumber_;
    yap::collection::Array<IPokemonSummaryWidget*> pokemonInfoPages_;

  protected:
    virtual bool HandleOnEvent (const yap::GuiEvent& guiEvent);

  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONINFOWIDGET_HPP
