#ifndef YAPOG_CLIENT_PLAYERDATA_HPP
# define YAPOG_CLIENT_PLAYERDATA_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Game/Player/PlayerTime.hpp"

namespace ycl
{
  class PlayerData
  {
    DISALLOW_COPY(PlayerData);

  public:

    PlayerData ();
    virtual ~PlayerData ();

    void ChangeMoney (int value);
    void UpdatePlayTime (const yap::Time& dt);

    ///@name Getters.
    ///{
    const yap::UInt32& GetMoney () const;
    const yap::Time& GetPlayTime () const;
    ///}

    ///@name Setters.
    ///{
    void RawSetMoney (const yap::UInt32& value);
    void RawSetPlayTime (const yap::Time& value);
    ///}

  private:
    yap::UInt32 money_;
    yap::PlayerTime playerTime_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_PLAYERDATA_HPP
