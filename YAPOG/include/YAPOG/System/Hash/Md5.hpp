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
	class YAPOG_LIB MD5
	{
		DISALLOW_COPY(MD5);
	public:
		MD5();
		MD5(const std::string& source);
		MD5(std::ifstream& file);
		MD5(const unsigned char* source, uint32 len);

		std::string Calculate(const std::string& source);
		std::string Calculate(std::ifstream& file);
		std::string Calculate(const unsigned char* source, uint32 len);

		std::string GetHash() const;
		const unsigned char* GetRawHash() const { return m_rawHash; }

	private:
		std::string     m_sHash;
		unsigned char m_rawHash[16];
	};
} // namespace yap

#endif // MD5_HPP
