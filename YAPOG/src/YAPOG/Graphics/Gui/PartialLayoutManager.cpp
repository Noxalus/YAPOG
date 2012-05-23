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
      layout_->Clear ();
      uint itemBeforeCount = (itemCount_ - 1) / 2;
      uint itemAfterCount = itemCount_ - itemBeforeCount - 1;
      uint it = MathHelper::Clamp<uint>(cursorCurSel_ - itemBeforeCount, 0, itemCount_);

      while (it < cursorCurSel_)
      {
        layout_->AddChild (*itemz_[it]);
      }

      it = cursorCurSel_;

      while (it < MathHelper::Clamp<uint>(cursorCurSel_ + itemAfterCount, 0, itemCount_))
      {
        layout_->AddChild (*itemz_[it]);
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
  void PartialLayoutManager::SetSize (uint size)
  {
    size_ = size;    
    itemCount_ = size / layout_->GetWidthItem ();;
    Refresh ();
  }
  uint PartialLayoutManager::GetSize () const
  {
    return size_;
  }

} //namespace yap