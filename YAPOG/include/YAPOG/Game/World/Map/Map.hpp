#ifndef YAPOG_MAP_HPP
# define YAPOG_MAP_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Factory/ILoadable.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  /// @brief Base Map class for both client and server.
  class YAPOG_LIB Map : public ILoadable
  {
    public:

      Map (const ID& id);
      virtual ~Map ();

      const ID& GetID () const;
      void SetID (const ID& id);

      const String& GetName () const;
      void SetName (const String& name);

    protected:

      /// @brief Copy constructor for Clone member.
      Map (const Map& copy);

    private:

      /// @brief Disabled.
      Map& operator= (const Map& copy);

      static const String DEFAULT_NAME;

      ID id_;
      String name_;
  };
} // namespace yap

#endif // YAPOG_MAP_HPP
