#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>
#include <SFML/Network.hpp>
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
	
	// List of name file needed to be download by the client
	yap::FileChecker::t_vs vc = fs.sendfiletodownload(fc);
	fc.update(vc);
	/*
	yap::FileChecker::t_vs::const_iterator it(vc.begin());
	yap::FileChecker::t_vs::const_iterator it_end(vc.end());
	*/
	// Network test
	
	getchar();
	return 0;
}