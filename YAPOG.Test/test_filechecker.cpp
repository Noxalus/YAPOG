#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>
#include "YAPOG/System/Hash/FileChecker.hpp"

int main()
{
	// SERVER
	// boost::filesystem::path t(boost::filesystem::current_path());
	boost::filesystem::path serv("D:\\git\\YAPOG_try");//(boost::filesystem::current_path());
	yap::FileChecker fs (serv);
	
	// Client
	boost::filesystem::path client("D:\\git\\YAPOG_try2");//(boost::filesystem::current_path());
	yap::FileChecker fc (client);
	
	// List of name file needed to be download by the client
	yap::FileChecker::t_vs vc = fs.SendFileToDownload(fc);
	// Network test
	fc.Update(vc);
	
	getchar();
	return 0;
}