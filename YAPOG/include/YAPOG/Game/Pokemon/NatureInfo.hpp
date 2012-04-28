#ifndef YAPOG_NATUREINFO_HPP
# define YAPOG_NATUREINFO_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Game/Factory/ILoadable.hpp"

namespace yap
{
  class YAPOG_LIB NatureInfo : public ILoadable
  {
  public:
    NatureInfo ();
    NatureInfo (const ID& id);
    NatureInfo (const NatureInfo& copy);

    /// @name ICloneable members.
    /// @{
    virtual NatureInfo* Clone () const;
    /// @}

    /// Getters
    const ID& GetID () const;
    const String& GetName () const;
    const float& GetAttackFactor () const;
    const float& GetDefenseFactor () const;
    const float& GetSpecialAttackFactor () const;
    const float& GetSpecialDefenseFactor () const;
    const float& GetSpeedFactor () const;

    /// Setters
    void SetID (const ID& id);
    void SetName (const String& name);
    void SetAttackFactor (const float& factor);
    void SetDefenseFactor (const float& factor);
    void SetSpecialAttackFactor (const float& factor);
    void SetSpecialDefenseFactor (const float& factor);
    void SetSpeedFactor (const float& factor);

  private:
    ID staticID_;
    String name_;
    float attackFactor_;
    float defenseFactor_;
    float specialAttackFactor_;
    float specialDefenseFactor_;
    float speedFactor_;

    static const float INITIAL_FACTOR_VALUE;
  };
} // namespace yap

#endif // YAPOG_NATUREINFO_HPP
