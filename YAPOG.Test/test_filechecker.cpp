#include <iostream>
#include <boost/filesystem.hpp>
#include "YAPOG/System/Hash/FileChecker.hpp"

int main()
{
	// SERVER
	// boost::filesystem::path t(boost::filesystem::current_path());
	boost::filesystem::path serv("D:\\git\\YAPOG_try");
	yap::FileChecker fs (serv);
	
	// Client
	boost::filesystem::path client("D:\\git\\YAPOG_try2");
	yap::FileChecker fc (client);
	
	yap::FileChecker::t_vs vc = fs.sendfiletodownload(fc);
	//yap::FileChecker::t_vf vc = fc.getv();
	yap::FileChecker::t_vs::const_iterator it(vc.begin());
	yap::FileChecker::t_vs::const_iterator it_end(vc.end());
	for (; it != it_end; it++)
	{
		std::cout << (*it) << std::endl;
	}
	
	getchar();
	return 0;
}