#ifndef YAPOG_CLIENT_BATTLEINFOWIDGET_HPP
# define YAPOG_CLIENT_BATTLEINFOWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/Label.hpp"
# include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
# include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
# include "YAPOG/Graphics/Texture.hpp"
# include "YAPOG/Game/Pokemon/Gender.hpp"

# include "Battle/BaseBattleWidget.hpp"

namespace yap
{
  class PictureBox;
} // namespace yap

namespace ycl
{
  class BattleInfoWidget : public BaseBattleWidget
  {
    DISALLOW_COPY (BattleInfoWidget);

  public:
    BattleInfoWidget ();

    void SetName (const yap::String& value);
    void SetLevel (int value);
    void SetGender (const yap::Gender& value);

    virtual void HandleDraw (yap::IDrawingContext& context);

  protected:
    /// @name Labels.
    /// @{
    yap::Label nameLabel_;
    yap::Label levelLabel_;
    /// @}

    /// @name Layouts.
    /// @{
    yap::HorizontalLayout nameBox_;
    yap::VerticalLayout genderBox_;
    yap::VerticalLayout levelBox_;
    yap::HorizontalLayout hpBox_;
    yap::VerticalLayout battleInfoBox_;
    /// @}

    /// @name Textures.
    /// @{
    //yap::Texture HPBarContent_;
    /// @}
    
    /// @name Picture boxes.
    /// @{
    yap::PictureBox* hpBarPictureBox_;
    yap::PictureBox* hpBarContent_;
    yap::PictureBox* genderPictureBox_;
    /// @}
  };
} // namespace ycl

#endif // YAPOG_CLIENT_BATTLEINFOWIDGET_HPP
