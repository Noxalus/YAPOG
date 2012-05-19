#ifndef YAPOG_MD5_HPP
# define YAPOG_MD5_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/System/IOStream.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
	class YAPOG_LIB Md5
	{
		DISALLOW_COPY(Md5);
	public:
		Md5();
		Md5(const String& source);
		Md5(IFStream& file);
		Md5(const uchar* source, Int32 len);

		String                Calculate(const String& source);
		String                Calculate(IFStream& file);
		String                Calculate(const uchar* source, Int32 len);

		String                GetHash() const;
		const uchar*          GetRawHash() const;

	private:
		String                msHash_;
		uchar                 mrawHash_[16];
	};
} // namespace yap

#endif // MD5_HPP
