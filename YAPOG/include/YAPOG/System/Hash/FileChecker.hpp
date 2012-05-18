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
		typedef struct MyFile
		{
			MyFile(std::string fn, size_t fs);

			std::string filename;
			size_t		filesize;
		} sMF;

		typedef std::vector<boost::filesystem::path> t_vp;
		typedef std::vector<FileChecker*> t_vf;
		typedef std::vector<sMF*> t_vs;

		FileChecker(boost::filesystem::path path);
		FileChecker(std::string filename);
		FileChecker(std::string filename, std::string md5, size_t filesize);
		~FileChecker();

		void		                SetFilename(std::string filename);
		void		                SetMd5(std::string md5);
		std::string	            GetFilename();
		int			                GetFilesize();
		std::string	            GetMd5();
		t_vf		                GetVfile();
		
		t_vs		                SendFileToDownload(FileChecker& fc);
		bool		                Update(t_vs vs);

	private:
		// Server checking.
		void		                GetFileToDownload();
		bool		                Compare(FileChecker* const c, FileChecker* const s);
		std::string	            VectorFind(t_vf vp, FileChecker* p);
		bool		                UpdateFTP(t_vs vs);

		t_vf		                vfile_;
		t_vs		                vstring_;
		boost::filesystem::path path_;
		std::string             filename_;
		size_t		              filesize_;
		std::string             md5_;
	};
} // namespace yap

#endif /* FILECHECKER_HPP */