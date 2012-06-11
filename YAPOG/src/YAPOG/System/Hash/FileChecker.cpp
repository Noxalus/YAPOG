#include "YAPOG/System/Hash/FileChecker.hpp"

namespace yap
{
  FileChecker::FileChecker (PathType path)
    : vfile_ ()
    , vstring_ ()
    , path_ (path)
    , filename_ ("")
    , filesize_ (0)
    , md5_ ("")
    , sizeDownloaded_ (0)
    , fileDownloaded_ (0)
  {
    GetFileToDownload ();
  }

  FileChecker::FileChecker (String filename)
    : vfile_ ()
    , vstring_ ()
    , path_ ("")
    , filename_ (filename)
    , filesize_ (0)
    , md5_ ("")
    , sizeDownloaded_ (0)
    , fileDownloaded_ (0)
  {
  }

  FileChecker::FileChecker (String filename,
    String md5,
    size_t filesize)
    : vfile_ ()
    , vstring_ ()
    , path_ ("")
    , filename_ (filename)
    , filesize_ (filesize)
    , md5_ (md5)
    , sizeDownloaded_ (0)
    , fileDownloaded_ (0)
  {
  }

  FileChecker::MyFile::MyFile (String fn,
    size_t fs)
    : Filename (fn)
    , Filesize (fs)
  {
  }

  FileChecker::~FileChecker ()
  {
    VFilesType::ItType it (vfile_.begin ());
    VFilesType::ItType it_end (vfile_.end ());

    VFileType::ItType its (vstring_.begin ());
    VFileType::ItType its_end (vstring_.end ());

    for (; it != it_end; it++)
      delete (*it);
    for (; its != its_end; its++)
      delete (*its);
  }

  void                    FileChecker::SetFilename (String filename)
  {
    filename_ = filename;
  }

  void                    FileChecker::SetMd5 (String md5)
  {
    md5_ = md5;
  }

  String                  FileChecker::GetFilename ()
  {
    return filename_;
  }

  String                  FileChecker::GetMd5 ()
  {
    return md5_;
  }

  size_t                  FileChecker::GetFilesize ()
  {
    return filesize_;
  }

  FileChecker::VFilesType FileChecker::GetVfile ()
  {
    return vfile_;
  }

  UInt64                  FileChecker::GetSizeDownloaded ()
  {
    return sizeDownloaded_;
  }

  UInt16                  FileChecker::GetFileDownloaded ()
  {
    return fileDownloaded_;
  }

  bool                    FileChecker::Compare (FileChecker* const c,
    FileChecker* const s)
  {
    return (c->GetFilename () == s->GetFilename ()
      && c->GetMd5 () == s->GetMd5 ());
  }

  void                    FileChecker::GetFileToDownload ()
  {
    VPathType vp;
    try
    {
      if (boost::filesystem::exists (path_))
      {
        yap::Md5 md5;
        std::copy (
          boost::filesystem::recursive_directory_iterator (path_),
          boost::filesystem::recursive_directory_iterator (),
          std::back_inserter (vp)
          );

        VPathType::const_iterator it(vp.begin ());
        VPathType::const_iterator it_end(vp.end ());

        for (; it != it_end; it++)
        {
          if (boost::filesystem::is_regular_file (*it))
          {
            int i = ((*it).string ()).length () + 1;
            int j = path_.string ().length ();
            i -= j;
            std::ifstream f;
            f.open(((*it).string ()).c_str ());
            String mymd5 = md5.Calculate (f);
            vfile_.Add(
              new FileChecker (
              ((*it).string ()).substr (path_.string ().length () + 1, i),
              mymd5,
              boost::filesystem::file_size ((*it).string ()))
              );
            f.close ();
          }
          if (boost::filesystem::is_directory((*it)))
          {
            int i = ((*it).string ()).length () + 1;
            int j = path_.string ().length ();
            i -= j;
            vfile_.Add (
              new FileChecker (((*it).string ()).
              substr(path_.string ().length () + 1, i),
              String ("0"), 0)
              );
          }
        }
      }
    }
    catch (const boost::filesystem::filesystem_error& ex)
    {
      std::cout << ex.what () << std::endl;
    }
  }

  String                  FileChecker::VectorFind (VFilesType vc,
    FileChecker* elt)
  {
    VFilesType::ItType it (vc.begin ());
    VFilesType::ItType it_end (vc.end ());
    String name;

    for (; it != it_end; it++)
    {
      name = (*it)->GetFilename ();
      if (name == elt->GetFilename ())
        if ((*it)->GetMd5 () != elt->GetMd5 ())
        {
          std::replace(name.begin (), name.end (), '\\', '/');
          return ((*it)->GetMd5 ().compare ("0") == 0 ? name + "0" : name);
        }
        else
          return "";
    }

    name = elt->GetFilename ();
    std::replace(name.begin (), name.end (), '\\', '/');
    return (elt->GetMd5 ().compare ("0") == 0 ? name + "0" : name);
  }

  void                    FileChecker::Launch (VFileType vs)
  {
    Thread* th = new Thread (MEMBER_WORKER(FileChecker::Update), vs);
    th->Launch ();
  }

  FileChecker::VFileType  FileChecker::SendFileToDownload (FileChecker& fc)
  {
    FileChecker::VFileType vbis;

    try
    {
      if (boost::filesystem::exists (path_))
      {
        VFilesType::ItType it (vfile_.begin ());
        VFilesType::ItType it_end (vfile_.end ());

        for (; it != it_end; it++)
        {
          String ret = VectorFind (fc.GetVfile (), (*it));
          if (!ret.empty())
            vbis.Add (new MyFile (ret, (*it)->GetFilesize ()));
        }
      }
    }
    catch (const boost::filesystem::filesystem_error& ex)
    {
      std::cout << ex.what () << std::endl;
    }

    return vbis;
  }

  bool                    FileChecker::UpdateFTP (VFileType vs)
  {
    sf::Ftp server;
    FileChecker::VFileType::ConstItType it (vs.begin ());
    FileChecker::VFileType::ConstItType it_end (vs.end ());
    String path = path_.string ();
    String address = "";
    String login = "";
    String pw = "";
    std::replace (path.begin (), path.end (), '\\', '/');

    if (server.connect (address).isOk ())
    {
      if (server.login (login, pw).isOk ())
      {
        server.changeDirectory ("test");
        server.keepAlive ();
        for (; it != it_end; it++)
        {
          String n = (*it)->Filename;
          std::replace (n.begin (), n.end (), '\\', '/');
          String newpath = "";

          int i = n.rfind ('/');
          bool dl = true;
          String name = n;
          server.keepAlive ();
          if (n[n.size () - 1] == '0')
          {
            dl = false;
            name = n.substr(0, n.size () - 1);
            boost::filesystem::create_directory(path + "/" + name);
          }
          else
          {
            if (i != String::npos)
            {
              name.assign (n, i + 1, n.size ());
              newpath.assign (n, 0, i);
            }
          }
          if (dl)
          {
            server.download (
              (newpath.empty () ? name : (newpath + "/" + name)).c_str (),
              (newpath.empty () ? path : (path + "/" + newpath)).c_str (), sf::Ftp::Binary);
          }
        }
      }
      server.disconnect ();
    }
    else
    {
      std::cout << "Failed to connect" << std::endl;
      return false;
    }

    return true;
  }

  bool                    FileChecker::Update(VFileType vs)
  {
    try
    {
      boost::asio::io_service io_service;
      size_t vectorSize = vs.Count ();

      // Get a list of endpoints corresponding to the server name.
      // Try each endpoint until we successfully establish a connection.
      FileChecker::VFileType::ConstItType it (vs.begin ());
      FileChecker::VFileType::ConstItType it_end (vs.end ());

      for (; it != it_end; it++)
      {
        sizeDownloaded_ = 0;
        boost::asio::ip::tcp::resolver resolver (io_service);
        boost::asio::ip::tcp::resolver::query query ("yapog.free.fr", "http");
        boost::asio::ip::tcp::resolver::iterator endpoint_iterator = resolver.resolve (query);
        boost::asio::ip::tcp::socket socket (io_service);
        boost::asio::connect (socket, endpoint_iterator);

        boost::asio::streambuf request;
        OStream request_stream (&request);
        String n = (*it)->Filename;
        std::replace (n.begin (), n.end (), '\\', '/');
        //String path = path_.string ();
        String path = "D:/git/YAPOG_downloadtest";
        String newpath = "";

        int i = n.rfind ('/');
        bool dl = true;
        String name = n;
        if (n[n.size () - 1] == '0')
        {
          dl = false;
          name = n.substr(0, n.size () - 1);
          boost::filesystem::create_directory (path + "/" + name);
        }
        else
        {
          if (i != String::npos)
          {
            name.assign (n, i + 1, n.size ());
            newpath.assign (n, 0, i);
          }
        }
        if (dl)
        {
          filename_ = name;
          request_stream << "GET " << ("/test/" + (newpath.empty () ? name : (newpath + "/" + name)))
            << " HTTP/1.0\r\n"
            << "Host: " << "yapog.free.fr" << "\r\n"
            << "Accept: */*\r\n"
            << "Connection: close\r\n\r\n";
          boost::asio::write (socket, request);

          boost::asio::streambuf response;
          boost::asio::read_until (socket, response, "\r\n");

          IStream response_stream (&response);
          String http_version;
          response_stream >> http_version;
          UInt32 status_code;
          response_stream >> status_code;
          String status_message;
          std::getline (response_stream, status_message);
          if (!response_stream || http_version.substr(0, 5) != "HTTP/")
          {
            std::cout << "Invalid response\r\n";
            return false;
          }
          if (status_code != 200)
          {
            std::cout << "Response returned with status code "
              << status_code << "\r\n";
            return false;
          }

          size_t bytes = (*it)->Filesize;
          boost::system::error_code error;
          OFStream outfile;
          std::stringstream ss;
          String str;
          outfile.open((newpath.empty () ? path + "/" + name : 
            (path + "/" + newpath + "/" + name)),
            std::ios::binary);
          size_t sizetotal = 0;

          while (boost::asio::read (socket, response,
            boost::asio::transfer_at_least (1), error))
          {
            float percentageSize = 0;
            sizetotal += response.size ();
            percentageSize = ((float) sizetotal / bytes * 100);
            sizeDownloaded_ = percentageSize;
            ss << &response;
          }
          str = ss.str ();
          if (sizetotal > bytes)
            str.erase (0, sizetotal - bytes);
          outfile << str;
          outfile.close();
          if (error != boost::asio::error::eof)
            throw boost::system::system_error (error);
          fileDownloaded_++;
        }
      }
    }
    catch (std::exception& e)
    {
      std::cout << "Exception: " << e.what () << std::endl;
      return false;
    }
    return true;
  }
}