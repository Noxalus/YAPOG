#include "YAPOG/Graphics/Gui/GuiManager.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/System/StringHelper.hpp"

#include "GameScreen/UpdateScreen.hpp"

namespace ycl
{
  const yap::ScreenType UpdateScreen::DEFAULT_NAME = "Update";

  UpdateScreen::UpdateScreen ()
    : BaseScreen (DEFAULT_NAME)
    , lastlength_ (0)
    , fc_ (nullptr)
    , fileName_ ()
    , backgroundbox_ (new yap::PictureBox ())
    , foregroundbox_ (new yap::PictureBox ())
    , filePercentage_ ()
    , fileDownloaded_ ()
    , totalFile_ ()
    , firstLayout_ (new yap::HorizontalLayout (yap::Padding (5, 5, 5, 5),
    yap::Padding (5, 5, 5, 5), false))
    , secondLayout_ (new yap::HorizontalLayout (yap::Padding (5, 5, 5, 5),
    yap::Padding (5, 10, 5, 5), false))
    , bigLayout_ (new yap::VerticalLayout (yap::Padding (5, 5, 5, 5),
    yap::Padding (5, 5, 5, 5), false))
  {
    firstLayout_->SetSize (yap::Vector2 (300, 75));
    secondLayout_->SetSize (yap::Vector2 (300, 75));
    bigLayout_->SetSize (yap::Vector2 (300, 150));
    bigLayout_->SetPosition (yap::Vector2 (50, 50));
    foregroundbox_->SetPicture ("WindowSkins/BasicSkin/Global/BarContent.png");
    backgroundbox_->SetPicture ("WindowSkins/BasicSkin/Global/Bar.png");
  }

  void UpdateScreen::HandleInit ()
  {
    BaseScreen::HandleInit ();
    
    yap::WidgetBackground* updaterBground = 
      new yap::WidgetBackground (
      "WindowSkins/BasicSkin/Global/WindowBackgroundTexture.png",
      true);
    yap::Texture* t = new yap::Texture ();
    t->LoadFromFile ("WindowSkins/BasicSkin/Global/TopBorder.png");
    yap::Texture* tr = new yap::Texture ();
    tr->LoadFromFile ("WindowSkins/BasicSkin/Global/TopRightCorner.png");
    yap::Texture* r = new yap::Texture ();
    r->LoadFromFile ("WindowSkins/BasicSkin/Global/RightBorder.png");
    yap::Texture* br = new yap::Texture ();
    br->LoadFromFile  ("WindowSkins/BasicSkin/Global/BottomRightCorner.png");
    yap::Texture* b = new yap::Texture ();
    b->LoadFromFile ("WindowSkins/BasicSkin/Global/BottomBorder.png");
    yap::Texture* bl = new yap::Texture ();
    bl->LoadFromFile ("WindowSkins/BasicSkin/Global/BottomLeftCorner.png");
    yap::Texture* l = new yap::Texture ();
    l->LoadFromFile ("WindowSkins/BasicSkin/Global/LeftBorder.png");
    yap::Texture* tl = new yap::Texture ();
    tl->LoadFromFile ("WindowSkins/BasicSkin/Global/TopLeftCorner.png");

    yap::WidgetBorder* updaterBorder =
      new yap::WidgetBorder (*t, *tr, *r, *br, *b, *bl, *l, *tl, true);

    boost::filesystem::path client ("G:\\YAPOG\\YAPOG_CLIENT"); //(boost::filesystem::current_path());
    fc_ = new yap::FileChecker (client);

    boost::filesystem::path serv ("G:\\YAPOG\\YAPOG_SERVER");//(boost::filesystem::current_path());
    yap::FileChecker fs (serv);

    // List of name file needed to be download by the client
    fs.SendFileToDownload(fc_);

    // Network test
    fc_->Launch ();
    
    backgroundbox_->SetSize (yap::Vector2 (
      157,
      21));
    foregroundbox_->ChangeColor (sf::Color::Green);
    backgroundbox_->AddChild (*foregroundbox_);
    foregroundbox_->Move (yap::Vector2 (7.f, 6.f));

    firstLayout_->AddChild (fileName_);
    secondLayout_->AddChild (*backgroundbox_);
    secondLayout_->AddChild (filePercentage_);
    secondLayout_->AddChild (fileDownloaded_);
    secondLayout_->AddChild (totalFile_);
    bigLayout_->AddChild (*firstLayout_);
    bigLayout_->AddChild (*secondLayout_);
    bigLayout_->SetBackground (*updaterBground);
    bigLayout_->SetBorder (*updaterBorder);
    guiManager_->AddChild (*bigLayout_);
  }

  UpdateScreen::~UpdateScreen ()
  {
    delete (foregroundbox_);
    foregroundbox_ = nullptr;
    delete (backgroundbox_);
    backgroundbox_ = nullptr;
    delete (firstLayout_);
    firstLayout_ = nullptr;
    delete (secondLayout_);
    secondLayout_ = nullptr;
    delete (bigLayout_);
    bigLayout_ = nullptr;
  }

  const yap::ScreenType& UpdateScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    Update ();

    return BaseScreen::HandleRun (dt, context);
  }
  
  void UpdateScreen::UpdateContentSize (int value)
  {
    float size = 144 * ((float)value / 100);

    foregroundbox_->SetSize (yap::Vector2 (
      size != 0 ? size : 1,
      9.5f));
  }

  void UpdateScreen::Update ()
  {
    yap::UInt32 totalFile = fc_->GetVFileToDl ().Count ();
    yap::UInt32 size = fc_->GetSizeDownloaded ();
    yap::String filesize = yap::StringHelper::ToString (size);
    yap::UInt16 length = filesize.length ();

    if (!fc_->GetDlEnd ())
    {
      fileName_.SetText (
        yap::StringHelper::ToString (fc_->GetFilename ()));
      filePercentage_.SetText (filesize);
      fileDownloaded_.SetText (
        yap::StringHelper::ToString (fc_->GetFileDownloaded ()));
      totalFile_.SetText ("/" +
        yap::StringHelper::ToString (totalFile));
      UpdateContentSize (size);
      if (lastlength_ != length)
      {
        lastlength_ = length;
        secondLayout_->Refresh ();
      }
    }
    else
      nextScreen_ = "Splash";
  }
} // namespace ycl
