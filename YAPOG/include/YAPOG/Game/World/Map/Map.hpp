#ifndef YAPOG_MAP_HPP
# define YAPOG_MAP_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  /// @brief Base Map class for both client and server.
  class YAPOG_LIB Map
  {
      DISALLOW_COPY(Map);

    public:

      Map (const ID& id);
      virtual ~Map ();

      const ID& GetID () const;
      void SetID (const ID& id);

      const String& GetName () const;
      void SetName (const String& name);

    private:

      static const String DEFAULT_NAME;

      ID id_;
      String name_;
  };
} // namespace yap

#endif // YAPOG_MAP_HPP
