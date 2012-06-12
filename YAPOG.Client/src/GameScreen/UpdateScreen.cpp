#include "GameScreen/UpdateScreen.hpp"
/// @warning Commented.
//#include "YAPOG/System/Hash/FileChecker.hpp"

namespace ycl
{
  const yap::ScreenType UpdateScreen::DEFAULT_NAME = "Update";

  UpdateScreen::UpdateScreen ()
    : BaseScreen (DEFAULT_NAME)
  {

  }

  void UpdateScreen::HandleInit ()
  {
    BaseScreen::HandleInit ();
  }

  UpdateScreen::~UpdateScreen ()
  {
  }

  const yap::ScreenType& UpdateScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    /// @warning Commented.
//    Update ();

    return BaseScreen::HandleRun (dt, context);
  }

  /// @warning Commented.
/*  void UpdateScreen::Update ()
  {

    boost::filesystem::path serv ("D:\\git\\YAPOG_try");//(boost::filesystem::current_path());
    yap::FileChecker fs (serv);

    // Client
    boost::filesystem::path client ("D:\\git\\YAPOG_try2");//(boost::filesystem::current_path());
    yap::FileChecker fc (client);

    // List of name file needed to be download by the client
    yap::FileChecker::VFileType vc = fs.SendFileToDownload(fc);

    // Network test
    fc.Launch (vc);

    getchar ();
    nextScreen_ = "Splash";
    }*/
} // namespace ycl
