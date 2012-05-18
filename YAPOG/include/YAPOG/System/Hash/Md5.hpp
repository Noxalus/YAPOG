#ifndef YAPOG_MD5_HPP
# define YAPOG_MD5_HPP

#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include "YAPOG/Macros.hpp"

#define uint32 unsigned int

namespace yap
{
	class YAPOG_LIB Md5
	{
		DISALLOW_COPY(Md5);
	public:
		Md5();
		Md5(const std::string& source);
		Md5(std::ifstream& file);
		Md5(const unsigned char* source, uint32 len);

		std::string Calculate(const std::string& source);
		std::string Calculate(std::ifstream& file);
		std::string Calculate(const unsigned char* source, uint32 len);

		std::string GetHash() const;
		const unsigned char* GetRawHash() const { return mrawHash_; }

	private:
		std::string     msHash_;
		unsigned char   mrawHash_[16];
	};
} // namespace yap

#endif // MD5_HPP
