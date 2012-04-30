#ifndef YAPOG_CLIENT_NPC_HPP
# define YAPOG_CLIENT_NPC_HPP

# include "YAPOG/Macros.hpp"
# include "World/Map/Character.hpp"

class NPC : public Character
{
    DISALLOW_ASSIGN(NPC);

  public:

    NPC (const yap::ID& id);
    virtual ~NPC ();

    /// @name ICloneable members.
    /// @{
    virtual NPC* Clone () const;
    /// @}

  protected:

    NPC (const NPC& copy);
};

#endif // YAPOG_CLIENT_NPC_HPP
