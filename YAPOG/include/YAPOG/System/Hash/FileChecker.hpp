#ifndef YAPOG_FILECHECKER_HPP
# define YAPOG_FILECHECKER_HPP

# include <cstdio>
# include <cstdlib>
# include <algorithm>
# include <string>
# include <vector>
# include <boost/filesystem.hpp>
# include <boost/asio.hpp>
# include <fstream>
# include <sstream>
# include <SFML/Network.hpp>
# include "YAPOG/System/Hash/Md5.hpp"
# include "YAPOG/Macros.hpp"

namespace yap
{
	class YAPOG_LIB FileChecker
	{
		DISALLOW_COPY(FileChecker);
	public:
		struct MyFile
		{
			MyFile(std::string fn, size_t fs);

			std::string filename;
			size_t		filesize;
		};

		typedef std::vector<boost::filesystem::path> t_vp;
		typedef std::vector<FileChecker*> t_vf;
		typedef std::vector<MyFile*> t_vs;

		FileChecker(boost::filesystem::path path);
		FileChecker(std::string filename);
		FileChecker(std::string filename, std::string md5, size_t filesize);
		~FileChecker();

		void		setfilename(std::string filename);
		void		setmd5(std::string md5);
		std::string	getfilename();
		int			getfilesize();
		std::string	getmd5();
		t_vf		getv();
		
		t_vs		sendfiletodownload(FileChecker& fc);
		bool		update(t_vs vs);

	private:
		// Server checking.
		void		getfiletodownload();
		bool		compare(FileChecker* const c, FileChecker* const s);
		std::string	vectorfind(t_vf vp, FileChecker* p);
		bool		updateFTP(t_vs vs);

		t_vf		v_;
		t_vs		vs_;
		boost::filesystem::path path_;
		std::string filename_;
		size_t		filesize_;
		std::string md5_;
	};
} // namespace yap

#endif /* FILECHECKER_HPP */