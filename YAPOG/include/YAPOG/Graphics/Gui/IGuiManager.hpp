#ifndef YAPOG_IGUIMANAGER_HPP
# define YAPOG_IGUIMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/IWidget.hpp"

namespace yap
{
  /// @brief Root Widget of a hierarchy that maintains every other one.
  struct YAPOG_LIB IGuiManager : public IWidget
  {
      virtual ~IGuiManager () {}
  };
} // namespace yap

#endif // YAPOG_IGUIMANAGER_HPP
