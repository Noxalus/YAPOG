#include "YAPOG/Graphics/Gui/LayoutBox.hpp"
#include "YAPOG/Graphics/Gui/PartialLayoutManager.hpp"
#include "YAPOG/System/MathHelper.hpp"

namespace yap
{

  PartialLayoutManager::PartialLayoutManager (LayoutBox& layout)
    : cursorCurSel_ (0)
    , itemCount_ (0)
    , size_ (0)
    , layout_ (&layout)
    , stock_ ()
    , itemz_ ()
    , isEnable_ (true)
    , widthItem_ (0)
  {
  }

  PartialLayoutManager::~PartialLayoutManager ()
  {
  }

  void PartialLayoutManager::SetEnable (bool state)
  {
    isEnable_ = state;
  }
  void PartialLayoutManager::Refresh ()
  {
    if (isEnable_)
    {
      uint countItem = 0;

      layout_->Clear ();
      uint itemBeforeCount = (itemCount_ - 1) / 2;
      uint itemAfterCount = itemCount_ - itemBeforeCount - 1;
      int endListHandle =  itemAfterCount -  (itemz_.Count ()  - 1 - cursorCurSel_) +1;
      endListHandle = (endListHandle >= 0) ? endListHandle : 0;
      uint it = MathHelper::Clamp<int>(cursorCurSel_ - itemBeforeCount - endListHandle, 0, cursorCurSel_);

      while (it < cursorCurSel_)
      {
        layout_->AddChild (*itemz_[it], yap::LayoutBox::Align::LEFT);
        it++;
        countItem++;
      }

      it = cursorCurSel_;

      while (it < itemz_.Count () && countItem <= itemCount_)
      {
        layout_->AddChild (*itemz_[it], yap::LayoutBox::Align::LEFT);
        it++;
        countItem++;
      }
    }
  }

  void PartialLayoutManager::AddItem (IWidget* items)
  {
    itemz_.Add (items);
  }

  void PartialLayoutManager::SetCurrentSel (uint curr)
  {
    cursorCurSel_ = curr;
    Refresh ();
  }
  void PartialLayoutManager::SetSize (float size)
  {    
    widthItem_ = layout_->GetWidthItem () + (layout_->GetInnerPadding ().top * 2);
    size_ = size;
    itemCount_ = size / widthItem_;
    Refresh ();
  }
  uint PartialLayoutManager::GetSize () const
  {
    return size_;
  }

} //namespace yap