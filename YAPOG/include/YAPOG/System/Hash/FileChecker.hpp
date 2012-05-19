#ifndef YAPOG_FILECHECKER_HPP
# define YAPOG_FILECHECKER_HPP

# include <boost/asio.hpp>
# include <boost/filesystem.hpp>
# include <sstream>
# include <vector>
# include <SFML/Network.hpp>
# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/System/IOStream.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/Hash/Md5.hpp"

namespace yap
{
	class YAPOG_LIB FileChecker
	{
		DISALLOW_COPY(FileChecker);
	public:
		typedef struct  MyFile
		{
			MyFile(String fn, size_t fs);

			String        Filename;
			size_t		    Filesize;
		} MyFileType;
    
		typedef boost::filesystem::path PathType;
		typedef std::vector<PathType> VPathType;
		typedef collection::Array<FileChecker*> VFilesType;
		typedef collection::Array<MyFileType*> VFileType;

		FileChecker(PathType path);
		FileChecker(String filename);
		FileChecker(String filename, String md5, size_t filesize);
		~FileChecker();

		void		          SetFilename(String filename);
		void		          SetMd5(String md5);
		String	          GetFilename();
		Int32			        GetFilesize();
		String	          GetMd5();
		VFilesType		    GetVfile();
		
		VFileType		      SendFileToDownload(FileChecker& fc);
		bool		          Update(VFileType vs);

	private:
		// Server checking.
		void		          GetFileToDownload();
		bool		          Compare(FileChecker* const c, FileChecker* const s);
		String	          VectorFind(VFilesType vp, FileChecker* p);
		bool		          UpdateFTP(VFileType vs);

		VFilesType		    vfile_;
		VFileType		      vstring_;
		PathType          path_;
		String            filename_;
		size_t		        filesize_;
		String            md5_;
	};
} // namespace yap

#endif /* FILECHECKER_HPP */