#ifndef YAPOG_PARTIAL_LAYOUT_MANAGER_HPP
# define YAPOG_PARTIAL_LAYOUT_MANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/LayoutBox.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"

namespace yap
{

  class YAPOG_LIB PartialLayoutManager
  {
    DISALLOW_COPY(PartialLayoutManager);

  public:    
    PartialLayoutManager (LayoutBox& layout);
    virtual ~PartialLayoutManager ();

    void SetCurrentSel (uint curr);
    void SetSize (uint size);
    void SetItems (collection::Array<IWidget*>& items);
    uint GetSize () const;
    void Refresh ();

  protected:       
    uint cursorCurSel_;
    uint itemCount_;
    uint size_;

    LayoutBox* layout_;

    collection::Array<IWidget*> stock_;
    collection::Array<IWidget*> itemz_;
  };
} // namespace yap

#endif /* YAPOG_PARTIAL_LAYOUT_MANAGER_HPP! */
