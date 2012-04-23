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

	FileChecker::t_vs FileChecker::filechecking(t_vf vc)
	{
		t_vs vf;
		t_vf::const_iterator itvs(v_.begin());
		t_vf::const_iterator itvs_end(v_.end());
		t_vf::const_iterator itvc(vc.begin());
		t_vf::const_iterator itvc_end(vc.end());

		for (; itvs != itvs_end; itvs++)
		{
			for (itvc = vc.begin(); itvc != itvc_end; itvc++)
			{
				if ((*itvc)->getfilename() == (*itvs)->getfilename())
				{
					if (!compare ((*itvc), (*itvs)))
						vf.push_back((*itvs)->getfilename());
					break;
				}
			}
		}

		return vf;
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
		for (; it != it_end; it++)
		{
			if ((*it)->getfilename() == elt->getfilename())
				if ((*it)->getmd5() != elt->getmd5())
					return (*it)->getfilename();
				else
					return "";
		}

		return elt->getfilename();
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
}