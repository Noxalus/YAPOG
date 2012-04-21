#ifndef YAPOG_CLIENT_MAP_HPP
# define YAPOG_CLIENT_MAP_HPP

# include "YAPOG/Game/World/Map/Map.hpp"

class Map : public yap::Map
{
  public:

    Map (const yap::ID& id);
    virtual ~Map ();

    virtual Map* Clone () const;

  private:

    /// @brief Copy constructor for Clone member.
    Map (const Map& copy);

    /// @brief Disabled.
    Map& operator= (const Map& copy);
};

#endif // YAPOG_CLIENT_MAP_HPP
