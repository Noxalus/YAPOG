#include "YAPOG/System/Hash/Md5.hpp"

namespace yap
{
  typedef struct {
		Int64 state[4];
		Int64 count[2];
		uchar buffer[64];
	} sMd5CTX;

	void                  MD5Init (sMd5CTX *);
	void                  MD5Update (sMd5CTX *,
                                   const uchar *,
                                   Int32);
	void                  MD5Final (uchar [16],
                                  sMd5CTX *);

	Md5::Md5()
	{
	}

	Md5::Md5(const String& source)
	{
		Calculate(source);
	}

	Md5::Md5(const uchar* source,
           Int32 len)
	{
		Calculate(source, len);
	}

	Md5::Md5(IFStream& file)
	{
		Calculate(file);
	}

	String                Md5::Calculate(const String& source)
	{
		return Calculate((const uchar*)source.c_str(), source.size());
	}

	String                Md5::Calculate(IFStream& file)
	{
		file.seekg(0, std::ios::end);

		Int32 length = file.tellg();

		file.seekg(0, std::ios::beg);

		char* buffer = new char [length];

		file.read(buffer, length);
		Calculate((uchar*) buffer, length);
		delete [] buffer;
		return msHash_;
	}

	String                Md5::Calculate(const uchar* source,
                                       Int32 len)
	{
		sMd5CTX context;

		MD5Init(&context);
		MD5Update(&context, source, len);
		MD5Final(mrawHash_, &context);

		msHash_.clear();
		msHash_.reserve(32);
		char buffer[3];
		buffer[2] = '\0';
		for (Int32 i = 0; i < 16; ++i)
		{
			sprintf(buffer, "%02x", mrawHash_[i]);
			msHash_ += buffer;
		}
		return msHash_;
	}

	String                Md5::GetHash() const
	{
		return msHash_;
	}

  const uchar*          Md5::GetRawHash() const
  {
    return mrawHash_;
  }

#pragma region Definition
#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21

	static void           MD5Transform (Int64 [4], const uchar [64]);
	static void           Encode (uchar *, const Int64 *, Int32);
	static void           Decode (Int64 *, const uchar *, Int32);
	static void MD5Memcpy (uchar*, uchar*, Int32);
	static void MD5Memset (uchar*, Int32, Int32);

	static uchar PADDING[64] = {
		0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	/* F, G, H and I are basic MD5 functions.
	*/
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

	/* ROTATE_LEFT rotates x left n bits.
	15-April-2003 Sony: use MSVC intrinsic to save some cycles
	*/
#ifdef _MSC_VER
#pragma intrinsic(_rotl)
#define ROTATE_LEFT(x, n) _rotl((x), (n))
#else
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))
#endif

	/* FF, GG, HH, and II transformations for rounds 1, 2, 3, and 4.
	Rotation is separate from addition to prevent recomputation.
	*/
#define FF(a, b, c, d, x, s, ac) { \
	(a) += F ((b), (c), (d)) + (x) + (Int64)(ac); \
	(a) = ROTATE_LEFT ((a), (s)); \
	(a) += (b); \
		}
#define GG(a, b, c, d, x, s, ac) { \
	(a) += G ((b), (c), (d)) + (x) + (Int64)(ac); \
	(a) = ROTATE_LEFT ((a), (s)); \
	(a) += (b); \
		}
#define HH(a, b, c, d, x, s, ac) { \
	(a) += H ((b), (c), (d)) + (x) + (Int64)(ac); \
	(a) = ROTATE_LEFT ((a), (s)); \
	(a) += (b); \
		}
#define II(a, b, c, d, x, s, ac) { \
	(a) += I ((b), (c), (d)) + (x) + (Int64)(ac); \
	(a) = ROTATE_LEFT ((a), (s)); \
	(a) += (b); \
		}
#pragma endregion

	/* MD5 initialization. Begins an MD5 operation, writing a new context. */
	void                  MD5Init (sMd5CTX *context)
	{
		context->count[0] = context->count[1] = 0;
		/* Load magic initialization constants. */
		context->state[0] = 0x67452301;
		context->state[1] = 0xefcdab89;
		context->state[2] = 0x98badcfe;
		context->state[3] = 0x10325476;
	}

	/* MD5 block update operation. Continues an MD5 message-digest
	operation, processing another message block, and updating the
	context. */
	void                  MD5Update (sMd5CTX *context,
                                   const uchar *input,
                                   Int32 inputLen)
	{
		Int32 i = 0;
    Int32 index = 0;
    Int32 partLen = 0;

		/* Compute number of bytes mod 64 */
		index = (Int32)((context->count[0] >> 3) & 0x3F);

		/* Update number of bits */
		if ((context->count[0] += ((Int64)inputLen << 3))
			< ((Int64)inputLen << 3))
			context->count[1]++;
		context->count[1] += ((Int64)inputLen >> 29);

		partLen = 64 - index;

		/* Transform as many times as possible. */
		if (inputLen >= partLen) {
			MD5Memcpy
				((uchar*)&context->buffer[index], (uchar*)input, partLen);
			MD5Transform (context->state, context->buffer);

			for (i = partLen; i + 63 < inputLen; i += 64)
				MD5Transform (context->state, &input[i]);

			index = 0;
		}

		/* Buffer remaining input */
		MD5Memcpy
			((uchar*)&context->buffer[index], (uchar*)&input[i],
			inputLen-i);
	}

	/* MD5 finalization. Ends an MD5 message-digest operation, writing the
	the message digest and zeroizing the context. */
	void                  MD5Final (uchar digest[16],
                                  sMd5CTX *context)
	{
		uchar bits[8];
		Int32 index = 0;
    Int32 padLen = 0;

		/* Save number of bits */
		Encode (bits, context->count, 8);

		/* Pad out to 56 mod 64.
		*/
		index = (Int32)((context->count[0] >> 3) & 0x3f);
		padLen = (index < 56) ? (56 - index) : (120 - index);
		MD5Update (context, PADDING, padLen);

		/* Append length (before padding) */
		MD5Update (context, bits, 8);
		/* Store state in digest */
		Encode (digest, context->state, 16);

		/* Zeroize sensitive information.
		*/
		MD5Memset ((uchar*)context, 0, sizeof (*context));
	}

	/* MD5 basic transformation. Transforms state based on block. */
	static void           MD5Transform (Int64 state[4],
                                      const uchar block[64])
	{
		Int64 a = state[0];
    Int64 b = state[1];
    Int64 c = state[2];
    Int64 d = state[3];
    Int64 x[16];

		Decode (x, block, 64);

		/* Round 1 */
		FF (a, b, c, d, x[ 0], S11, 0xd76aa478); /* 1 */
		FF (d, a, b, c, x[ 1], S12, 0xe8c7b756); /* 2 */
		FF (c, d, a, b, x[ 2], S13, 0x242070db); /* 3 */
		FF (b, c, d, a, x[ 3], S14, 0xc1bdceee); /* 4 */
		FF (a, b, c, d, x[ 4], S11, 0xf57c0faf); /* 5 */
		FF (d, a, b, c, x[ 5], S12, 0x4787c62a); /* 6 */
		FF (c, d, a, b, x[ 6], S13, 0xa8304613); /* 7 */
		FF (b, c, d, a, x[ 7], S14, 0xfd469501); /* 8 */
		FF (a, b, c, d, x[ 8], S11, 0x698098d8); /* 9 */
		FF (d, a, b, c, x[ 9], S12, 0x8b44f7af); /* 10 */
		FF (c, d, a, b, x[10], S13, 0xffff5bb1); /* 11 */
		FF (b, c, d, a, x[11], S14, 0x895cd7be); /* 12 */
		FF (a, b, c, d, x[12], S11, 0x6b901122); /* 13 */
		FF (d, a, b, c, x[13], S12, 0xfd987193); /* 14 */
		FF (c, d, a, b, x[14], S13, 0xa679438e); /* 15 */
		FF (b, c, d, a, x[15], S14, 0x49b40821); /* 16 */

		/* Round 2 */
		GG (a, b, c, d, x[ 1], S21, 0xf61e2562); /* 17 */
		GG (d, a, b, c, x[ 6], S22, 0xc040b340); /* 18 */
		GG (c, d, a, b, x[11], S23, 0x265e5a51); /* 19 */
		GG (b, c, d, a, x[ 0], S24, 0xe9b6c7aa); /* 20 */
		GG (a, b, c, d, x[ 5], S21, 0xd62f105d); /* 21 */
		GG (d, a, b, c, x[10], S22,  0x2441453); /* 22 */
		GG (c, d, a, b, x[15], S23, 0xd8a1e681); /* 23 */
		GG (b, c, d, a, x[ 4], S24, 0xe7d3fbc8); /* 24 */
		GG (a, b, c, d, x[ 9], S21, 0x21e1cde6); /* 25 */
		GG (d, a, b, c, x[14], S22, 0xc33707d6); /* 26 */
		GG (c, d, a, b, x[ 3], S23, 0xf4d50d87); /* 27 */
		GG (b, c, d, a, x[ 8], S24, 0x455a14ed); /* 28 */
		GG (a, b, c, d, x[13], S21, 0xa9e3e905); /* 29 */
		GG (d, a, b, c, x[ 2], S22, 0xfcefa3f8); /* 30 */
		GG (c, d, a, b, x[ 7], S23, 0x676f02d9); /* 31 */
		GG (b, c, d, a, x[12], S24, 0x8d2a4c8a); /* 32 */

		/* Round 3 */
		HH (a, b, c, d, x[ 5], S31, 0xfffa3942); /* 33 */
		HH (d, a, b, c, x[ 8], S32, 0x8771f681); /* 34 */
		HH (c, d, a, b, x[11], S33, 0x6d9d6122); /* 35 */
		HH (b, c, d, a, x[14], S34, 0xfde5380c); /* 36 */
		HH (a, b, c, d, x[ 1], S31, 0xa4beea44); /* 37 */
		HH (d, a, b, c, x[ 4], S32, 0x4bdecfa9); /* 38 */
		HH (c, d, a, b, x[ 7], S33, 0xf6bb4b60); /* 39 */
		HH (b, c, d, a, x[10], S34, 0xbebfbc70); /* 40 */
		HH (a, b, c, d, x[13], S31, 0x289b7ec6); /* 41 */
		HH (d, a, b, c, x[ 0], S32, 0xeaa127fa); /* 42 */
		HH (c, d, a, b, x[ 3], S33, 0xd4ef3085); /* 43 */
		HH (b, c, d, a, x[ 6], S34,  0x4881d05); /* 44 */
		HH (a, b, c, d, x[ 9], S31, 0xd9d4d039); /* 45 */
		HH (d, a, b, c, x[12], S32, 0xe6db99e5); /* 46 */
		HH (c, d, a, b, x[15], S33, 0x1fa27cf8); /* 47 */
		HH (b, c, d, a, x[ 2], S34, 0xc4ac5665); /* 48 */

		/* Round 4 */
		II (a, b, c, d, x[ 0], S41, 0xf4292244); /* 49 */
		II (d, a, b, c, x[ 7], S42, 0x432aff97); /* 50 */
		II (c, d, a, b, x[14], S43, 0xab9423a7); /* 51 */
		II (b, c, d, a, x[ 5], S44, 0xfc93a039); /* 52 */
		II (a, b, c, d, x[12], S41, 0x655b59c3); /* 53 */
		II (d, a, b, c, x[ 3], S42, 0x8f0ccc92); /* 54 */
		II (c, d, a, b, x[10], S43, 0xffeff47d); /* 55 */
		II (b, c, d, a, x[ 1], S44, 0x85845dd1); /* 56 */
		II (a, b, c, d, x[ 8], S41, 0x6fa87e4f); /* 57 */
		II (d, a, b, c, x[15], S42, 0xfe2ce6e0); /* 58 */
		II (c, d, a, b, x[ 6], S43, 0xa3014314); /* 59 */
		II (b, c, d, a, x[13], S44, 0x4e0811a1); /* 60 */
		II (a, b, c, d, x[ 4], S41, 0xf7537e82); /* 61 */
		II (d, a, b, c, x[11], S42, 0xbd3af235); /* 62 */
		II (c, d, a, b, x[ 2], S43, 0x2ad7d2bb); /* 63 */
		II (b, c, d, a, x[ 9], S44, 0xeb86d391); /* 64 */

		state[0] += a;
		state[1] += b;
		state[2] += c;
		state[3] += d;

		/* Zeroize sensitive information. */
		MD5Memset ((uchar*)x, 0, sizeof (x));
	}

	/* Encodes input (Int64) into output (uchar). Assumes len is
	a multiple of 4. */
	static void           Encode (uchar *output,
                                const Int64 *input,
                                Int32 len)
	{
		Int32 i, j;

		for (i = 0, j = 0; j < len; i++, j += 4) {
			output[j] = (uchar)(input[i] & 0xff);
			output[j+1] = (uchar)((input[i] >> 8) & 0xff);
			output[j+2] = (uchar)((input[i] >> 16) & 0xff);
			output[j+3] = (uchar)((input[i] >> 24) & 0xff);
		}
	}

	/* Decodes input (uchar) into output (Int64). Assumes len is
	a multiple of 4. */
	static void           Decode (Int64 *output,
                                const uchar *input,
                                Int32 len)
	{
		Int32 i, j;

		for (i = 0, j = 0; j < len; i++, j += 4)
			output[i] = ((Int64)input[j]) | (((Int64)input[j+1]) << 8) |
			(((Int64)input[j+2]) << 16) | (((Int64)input[j+3]) << 24);
	}

	/* Note: Replace "for loop" with standard memcpy if possible. */
	static void           MD5Memcpy (uchar* output,
                                   uchar* input,
                                   Int32 len)
	{
		Int32 i;

		for (i = 0; i < len; i++)
			output[i] = input[i];
	}

	/* Note: Replace "for loop" with standard memset if possible. */
	static void           MD5Memset (uchar* output,
                                   Int32 value,
                                   Int32 len)
	{
		Int32 i;

		for (i = 0; i < len; i++)
			((char *)output)[i] = (char)value;
	}
}