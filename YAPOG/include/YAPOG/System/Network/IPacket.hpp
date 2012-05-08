#ifndef YAPOG_IPACKET_HPP
# define YAPOG_IPACKET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/IWriter.hpp"
# include "YAPOG/System/IO/IReader.hpp"

namespace yap
{
  struct IPacket : public IWriter
                 , public IReader
  {
      virtual ~IPacket () { }
  };
} // namespace yap

#endif // YAPOG_IPACKET_HPP
