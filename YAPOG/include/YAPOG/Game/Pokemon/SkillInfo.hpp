#ifndef YAPOG_SKILLINFO_HPP
# define YAPOG_SKILLINFO_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Game/Factory/IIDLoadable.hpp"

namespace yap
{
  class YAPOG_LIB SkillInfo : public IIDLoadable
  {
  public:
    SkillInfo ();
    SkillInfo (const ID& id);
    SkillInfo (const SkillInfo& copy);

    /// @name ICloneable members.
    /// @{
    virtual SkillInfo* Clone () const;
    /// @}

    /// Getters
    const ID& GetID () const;
    const String& GetName () const;
    const String& GetDescription () const;
    const UInt16& GetPower () const;
    const UInt16& GetPP () const;
    const UInt16& GetMaxPP () const;
    const UInt16& GetAccuracy () const;
    const UInt16& GetType () const;
    const UInt16& GetCategory () const;
    const UInt16& GetTarget () const;
    const UInt16& GetEffect () const;
    const UInt16& GetUse () const;
    const UInt16& GetPriority () const;

    /// Setters
    void SetID (const ID& id);
    void SetName (const String& name);
    void SetDescription (const String& description);
    void SetPower (const UInt16& value);
    void  SetPP (const UInt16& value);
    void  SetMaxPP (const UInt16& value);
    void  SetAccuracy (const UInt16& value);
    void  SetType (const UInt16& value);
    void  SetCategory (const UInt16& value);
    void  SetTarget (const UInt16& value);
    void  SetEffect (const UInt16& value);
    void  SetUse (const UInt16& value);
    void  SetPriority (const UInt16& value);

  private:
    ID staticID_;
    String name_;
    String description_;
    UInt16 power_;
    UInt16 pp_;
    UInt16 maxPP_;
    UInt16 accuracy_;
    UInt16 type_;
    UInt16 category_;
    UInt16 target_;
    UInt16 effect_;
    UInt16 use_;
    UInt16 priority_;

    static const ID DEFAULT_ID;
    static const String DEFAULT_NAME;
    static const String DEFAULT_DESCRIPTION;
    static const UInt16 DEFAULT_POWER;
    static const UInt16 DEFAULT_PP;
    static const UInt16 DEFAULT_MAX_PP;
    static const UInt16 DEFAULT_ACCURACY;
    static const UInt16 DEFAULT_TYPE;
    static const UInt16 DEFAULT_CATEGORY;
    static const UInt16 DEFAULT_TARGET;
    static const UInt16 DEFAULT_EFFECT;
    static const UInt16 DEFAULT_USE;
    static const UInt16 DEFAULT_PRIORITY;
  };
} // namespace yap

#endif // YAPOG_SKILLINFO_HPP
