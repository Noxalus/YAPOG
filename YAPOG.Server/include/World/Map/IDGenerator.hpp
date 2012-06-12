#ifndef YAPOG_SERVER_IDGENERATOR_HPP
# define YAPOG_SERVER_IDGENERATOR_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"

namespace yse
{
  class IDGenerator
  {
      DISALLOW_COPY(IDGenerator);

    public:

      static IDGenerator& Instance ();

      yap::ID GetID ();

    private:

      IDGenerator ();
      ~IDGenerator ();

      yap::ID::ValueType currentID_;
  };
} // namespace yse

#endif // YAPOG_SERVER_IDGENERATOR_HPP
