#include "YAPOG/System/Hash/FileChecker.hpp"

namespace yap
{
	FileChecker::FileChecker(boost::filesystem::path path)
	{
		path_ = path;
		GetFileToDownload();
		filename_ = "";
		md5_ = "";
		filesize_ = 0;
	}

	FileChecker::FileChecker(std::string filename)
	{
		path_ = "";
		filename_ = filename;
		md5_ = "";
		filesize_ = 0;
	}

	FileChecker::FileChecker(std::string filename, std::string md5, size_t filesize)
	{
		path_ = "";
		filename_ = filename;
		md5_ = md5;
		filesize_ = filesize;
	}

	FileChecker::MyFile::MyFile(std::string fn, size_t fs)
	{
		filename = fn;
		filesize = fs;
	}

	FileChecker::~FileChecker()
	{
		t_vf::iterator it(vfile_.begin());
		t_vf::iterator it_end(vfile_.end());
		
		t_vs::iterator its(vstring_.begin());
		t_vs::iterator its_end(vstring_.end());

		for (; it != it_end; it++)
			delete(*it);
		for (; its != its_end; its++)
			delete(*its);
	}

	void FileChecker::SetFilename(std::string filename)
	{
		filename_ = filename;
	}

	void FileChecker::SetMd5(std::string md5)
	{
		md5_ = md5;
	}

	std::string FileChecker::GetFilename()
	{
		return filename_;
	}

	std::string FileChecker::GetMd5()
	{
		return md5_;
	}
	
	int FileChecker::GetFilesize()
	{
		return filesize_;
	}

	FileChecker::t_vf FileChecker::GetVfile()
	{
		return vfile_;
	}

	bool FileChecker::Compare(FileChecker* const c, FileChecker* const s)
	{
		return (c->GetFilename() == s->GetFilename()
			&& c->GetMd5 () == s->GetMd5());
	}

	void FileChecker::GetFileToDownload()
	{
		t_vp vp;
		try
		{
			if(boost::filesystem::exists(path_))
			{
				yap::Md5 md5;
				std::copy(
					boost::filesystem::recursive_directory_iterator(path_),
					boost::filesystem::recursive_directory_iterator(),
					std::back_inserter(vp)
					);

				t_vp::const_iterator it(vp.begin());
				t_vp::const_iterator it_end(vp.end());

				for (; it != it_end; it++)
				{
					if (boost::filesystem::is_regular_file(*it))
					{
						int i = ((*it).string()).length() + 1;
						int j = path_.string().length();
						i -= j;
						std::ifstream f;
						f.open(((*it).string()).c_str());
						std::string mymd5 = md5.Calculate(f);
						vfile_.push_back(
							new FileChecker (((*it).string()).
							substr(path_.string().length() + 1, i),
							mymd5, boost::filesystem::file_size((*it).string()))
							);
						f.close();
					}
					if (boost::filesystem::is_directory((*it)))
					{
						int i = ((*it).string()).length() + 1;
						int j = path_.string().length();
						i -= j;
						vfile_.push_back(
							new FileChecker (((*it).string()).
							substr(path_.string().length() + 1, i),
							std::string ("0"), 0)
							);
					}
				}
			}
		}
		catch (const boost::filesystem::filesystem_error& ex)
		{
			std::cout << ex.what() << std::endl;
		}
	}

	std::string FileChecker::VectorFind(t_vf vc, FileChecker* elt)
	{
		t_vf::iterator it(vc.begin());
		t_vf::iterator it_end(vc.end());
		std::string name;

		for (; it != it_end; it++)
		{
			name = (*it)->GetFilename();
			if (name == elt->GetFilename())
				if ((*it)->GetMd5() != elt->GetMd5())
				{
					std::replace(name.begin(), name.end(), '\\', '/');
					return ((*it)->GetMd5().compare("0") == 0 ? name + "0" : name);
				}
				else
					return "";
		}

		name = elt->GetFilename();
		std::replace(name.begin(), name.end(), '\\', '/');
		return (elt->GetMd5().compare("0") == 0 ? name + "0" : name);
	}

	FileChecker::t_vs FileChecker::SendFileToDownload(FileChecker& fc)
	{
		FileChecker::t_vs vbis;

		try
		{
			if(boost::filesystem::exists(path_))
			{
				t_vf::iterator it(vfile_.begin());
				t_vf::iterator it_end(vfile_.end());

				for (; it != it_end; it++)
				{
					std::string ret = VectorFind(fc.GetVfile(), (*it));
					if (!ret.empty())
						vbis.push_back(new MyFile(ret, (*it)->GetFilesize()));
				}
			}
		}
		catch (const boost::filesystem::filesystem_error& ex)
		{
			std::cout << ex.what() << std::endl;
		}

		return vbis;
	}

	bool FileChecker::UpdateFTP(FileChecker::t_vs vs)
	{
		sf::Ftp server;
		FileChecker::t_vs::const_iterator it(vs.begin());
		FileChecker::t_vs::const_iterator it_end(vs.end());
		std::string path = "D:\\git\\YAPOG_downloadtest";
		std::string address = "";
		std::string login = "";
		std::string pw = "";
		std::replace(path.begin(), path.end(), '\\', '/');

		if (server.connect(address).isOk())
		{
			if (server.login(login, pw).isOk())
			{
				server.changeDirectory("test");
				server.keepAlive();
				for (; it != it_end; it++)
				{
					std::string n = (*it)->filename;
					std::replace (n.begin(), n.end(), '\\', '/');
					std::string newpath = "";

					int i = n.rfind('/');
					bool dl = true;
					std::string name = n;
					server.keepAlive();
					if (n[n.size() - 1] == '0')
					{
						dl = false;
						name = n.substr(0, n.size() - 1);
						boost::filesystem::create_directory(path + "/" + name);
					}
					else
					{
						if (i != std::string::npos)
						{
							name.assign(n, i + 1, n.size());
							newpath.assign(n, 0, i);
						}
					}
					if (dl)
					{
						server.download(
							(newpath.empty() ? name : (newpath + "/" + name)).c_str(),
							(newpath.empty() ? path : (path + "/" + newpath)).c_str(), sf::Ftp::Binary);
					}
				}
			}
			server.disconnect();
		}
		else
		{
			std::cout << "Failed to connect" << std::endl;
			return false;
		}

		return true;
	}

	bool FileChecker::Update(FileChecker::t_vs vs)
	{
		try
		{
			boost::asio::io_service io_service;

			// Get a list of endpoints corresponding to the server name.
			// Try each endpoint until we successfully establish a connection.
			FileChecker::t_vs::const_iterator it(vs.begin());
			FileChecker::t_vs::const_iterator it_end(vs.end());

			for (; it != it_end; it++)
			{
				boost::asio::ip::tcp::resolver resolver(io_service);
				boost::asio::ip::tcp::resolver::query query("yapog.free.fr", "http");
				boost::asio::ip::tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
				boost::asio::ip::tcp::socket socket(io_service);
				boost::asio::connect(socket, endpoint_iterator);

				boost::asio::streambuf request;
				std::ostream request_stream(&request);
				std::string n = (*it)->filename;
				std::replace (n.begin(), n.end(), '\\', '/');
				std::string path = path_.string();//"D:/git/YAPOG_downloadtest";
				std::string newpath = "";

				std::cout << path << std::endl;
				int i = n.rfind('/');
				bool dl = true;
				std::string name = n;
				if (n[n.size() - 1] == '0')
				{
					dl = false;
					name = n.substr(0, n.size() - 1);
					boost::filesystem::create_directory(path + "/" + name);
				}
				else
				{
					if (i != std::string::npos)
					{
						name.assign(n, i + 1, n.size());
						newpath.assign(n, 0, i);
					}
				}
				if (dl)
				{
					request_stream << "GET " << ("/test/" + (newpath.empty() ? name : (newpath + "/" + name)))
						<< " HTTP/1.0\r\n"
						<< "Host: " << "yapog.free.fr" << "\r\n"
						<< "Accept: */*\r\n"
						<< "Connection: close\r\n\r\n";
					boost::asio::write(socket, request);

					boost::asio::streambuf response;
					boost::asio::read_until(socket, response, "\r\n");

					std::istream response_stream(&response);
					std::string http_version;
					response_stream >> http_version;
					unsigned int status_code;
					response_stream >> status_code;
					std::string status_message;
					std::getline(response_stream, status_message);
					if (!response_stream || http_version.substr(0, 5) != "HTTP/")
					{
						std::cout << "Invalid response\n";
						return false;
					}
					if (status_code != 200)
					{
						std::cout << "Response returned with status code " << status_code << "\n";
						return false;
					}

					size_t bytes = (*it)->filesize;
					boost::system::error_code error;
					std::ofstream outfile;
					outfile.open((newpath.empty() ? path + "/" + name : (path + "/" + newpath + "/" + name)), std::ios::binary);
					while (boost::asio::read(socket, response,
						boost::asio::transfer_exactly(bytes), error))
					{
						if (response.size() > bytes)
							response.consume(response.size() - bytes);
						outfile << &response;
					}
					outfile.close();
					if (error != boost::asio::error::eof)
						throw boost::system::system_error(error);
				}
			}
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << "\n";
			return false;
		}
		return true;
	}
}