#ifndef YAPOG_FILECHECKER_HPP
# define YAPOG_FILECHECKER_HPP

# include <boost/asio.hpp>
# include <boost/filesystem.hpp>
# include <sstream>
# include <vector>
# include <SFML/Network.hpp>
# include "YAPOG/System/Thread/Thread.hpp"
# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"
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
			MyFile (String fn, size_t fs);

			String        Filename;
			size_t	    Filesize;
		} MyFileType;
    
		typedef boost::filesystem::path PathType;
		typedef std::vector<PathType> VPathType;
		typedef collection::Array<FileChecker*> VFilesType;
		typedef collection::Array<MyFileType*> VFileType;

		FileChecker (PathType path);
		FileChecker (String filename);
		FileChecker (String filename, String md5, size_t filesize);
		~FileChecker ();

		void		          SetFilename (String filename);
		void		          SetMd5 (String md5);
    void              SetDlEnd (bool dl);

		String	          GetFilename ();
		size_t  	        GetFilesize ();
		String	          GetMd5 ();
		VFilesType		    GetVfile ();
		UInt64            GetSizeDownloaded ();
		UInt16            GetFileDownloaded ();
    bool              GetDlEnd ();
    VFileType&        GetVFileToDl ();

    void              Launch ();
		void    		      SendFileToDownload (FileChecker* fc);
    bool		          Update (FileChecker* fc);

	private:
		// Server checking.
		void		          GetFileToDownload ();
		bool		          Compare (FileChecker* const c, FileChecker* const s);
		String	          VectorFind (VFilesType vp, FileChecker* p);
		bool		          UpdateFTP (FileChecker* fc);

		VFilesType		    vfile_;
		VFileType		      vstring_;
		PathType          path_;
		String            filename_;
		size_t  	        filesize_;
		String            md5_;
    UInt64            sizeDownloaded_;
    UInt16            fileDownloaded_;
		VFileType		      vfiletodl_;
    bool              dlend_;
	};
} // namespace yap

#endif /* FILECHECKER_HPP */