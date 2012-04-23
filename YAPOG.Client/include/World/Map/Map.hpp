#ifndef YAPOG_CLIENT_MAP_HPP
# define YAPOG_CLIENT_MAP_HPP

# include "YAPOG/Game/World/Map/Map.hpp"

class Map : public yap::Map
{
  public:

    Map (const yap::ID& id);
    virtual ~Map ();

    /// @name ICloneable members.
    /// @{
    virtual Map* Clone () const;
    /// @}

  protected:

    /// @brief Copy constructor for Clone member.
    Map (const Map& copy);

  private:

    /// @brief Disabled.
    Map& operator= (const Map& copy);
};

#endif // YAPOG_CLIENT_MAP_HPP
