#ifndef YAPOG_GUI_MANAGER_HPP
# define YAPOG_GUI_MANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/IGuiManager.hpp"

namespace yap
{
  class YAPOG_LIB GuiManager : public IGuiManager
  {
    DISALLOW_COPY(GuiManager);

  public:
    GuiManager ();
    virtual ~GuiManager ();

  private:

  };
} // namespace yap

#endif /* YAPOG_GUI_MANAGER_HPP! */