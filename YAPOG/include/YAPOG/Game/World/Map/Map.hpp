#ifndef YAPOG_MAP_HPP
# define YAPOG_MAP_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/IClonable.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  /// @brief Base Map class for both client and server.
  class Map : public IClonable
  {
    public:

      DISALLOW_COPY(Map);

      Map ();
      virtual ~Map ();

      const ID& GetID () const;
      void ChangeID (const ID& id);

      const String& GetName () const;
      void SetName (const String& name);

    private:

      ID id_;
      String name_;
  };
} // namespace yap

#endif // YAPOG_MAP_HPP
