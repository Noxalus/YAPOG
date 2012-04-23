#include "YAPOG/System/Hash/FileChecker.hpp"

namespace yap
{
	FileChecker::FileChecker(boost::filesystem::path path)
	{
		path_ = path;
		getfiletodownload();
		filename_ = "";
		md5_ = "";
	}

	FileChecker::FileChecker(std::string filename)
	{
		path_ = "";
		filename_ = filename;
		md5_ = "";
	}

	FileChecker::FileChecker(std::string filename, std::string md5)
	{
		path_ = "";
		filename_ = filename;
		md5_ = md5;
	}

	FileChecker::~FileChecker()
	{
		t_vf::iterator it(v_.begin());
		t_vf::iterator it_end(v_.end());

		for (; it != it_end; it++)
			delete(*it);
	}

	void FileChecker::setfilename(std::string filename)
	{
		filename_ = filename;
	}

	void FileChecker::setmd5(std::string md5)
	{
		md5_ = md5;
	}

	std::string FileChecker::getfilename()
	{
		return filename_;
	}

	std::string FileChecker::getmd5()
	{
		return md5_;
	}
	
	FileChecker::t_vf FileChecker::getv()
	{
		return v_;
	}

	bool FileChecker::compare(FileChecker* const c, FileChecker* const s)
	{
		return (c->getfilename() == s->getfilename()
			&& c->getmd5() == s->getmd5());
	}

	void FileChecker::getfiletodownload()
	{
		t_vp vp;
		try
		{
			if(boost::filesystem::exists(path_))
			{
				yap::MD5 md5;
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
						v_.push_back(
							new FileChecker (((*it).string()).
							substr(path_.string().length() + 1, i),
							mymd5)
							);
						f.close();
					}
					if (boost::filesystem::is_directory((*it)))
					{
						int i = ((*it).string()).length() + 1;
						int j = path_.string().length();
						i -= j;
						v_.push_back(
							new FileChecker (((*it).string()).
							substr(path_.string().length() + 1, i),
							std::string ("0"))
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

	std::string FileChecker::vectorfind(t_vf vc, FileChecker* elt)
	{
		t_vf::iterator it(vc.begin());
		t_vf::iterator it_end(vc.end());
		std::string name;

		for (; it != it_end; it++)
		{
			name = (*it)->getfilename();
			if (name == elt->getfilename())
				if ((*it)->getmd5() != elt->getmd5())
				{
					std::replace(name.begin(), name.end(), '\\', '/');
					return ((*it)->getmd5().compare("0") == 0 ? name + "0" : name);
				}
				else
					return "";
		}
		
		name = elt->getfilename();
		std::replace(name.begin(), name.end(), '\\', '/');
		return (elt->getmd5().compare("0") == 0 ? name + "0" : name);
	}

	FileChecker::t_vs FileChecker::sendfiletodownload(FileChecker& fc)
	{
		FileChecker::t_vs vbis;

		try
		{
			if(boost::filesystem::exists(path_))
			{
				t_vf::iterator it(v_.begin());
				t_vf::iterator it_end(v_.end());

				for (; it != it_end; it++)
				{
					std::string ret = vectorfind(fc.getv(), (*it));
					if (!ret.empty())
						vbis.push_back(ret);
				}
			}
		}
		catch (const boost::filesystem::filesystem_error& ex)
		{
			std::cout << ex.what() << std::endl;
		}

		return vbis;
	}

	bool FileChecker::update(FileChecker::t_vs vs)
	{
		sf::Ftp server;
		FileChecker::t_vs::const_iterator it(vs.begin());
		FileChecker::t_vs::const_iterator it_end(vs.end());
		std::string path = "D:\\git\\YAPOG_downloadtest";

		std::replace(path.begin(), path.end(), '\\', '/');
		
		if (server.connect("ftpperso.free.fr").isOk())
		{
			if (server.login("yapog", "COUCOU").isOk())
			{
				server.changeDirectory("test");
				server.keepAlive();
				for (; it != it_end; it++)
				{
					std::string n = (*it);
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
}