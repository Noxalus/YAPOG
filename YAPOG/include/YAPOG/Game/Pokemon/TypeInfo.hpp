#ifndef YAPOG_TYPEINFO_HPP
# define YAPOG_TYPEINFO_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Game/Factory/IIDLoadable.hpp"

namespace yap
{
  class YAPOG_LIB TypeInfo : public IIDLoadable
  {
  public:
    TypeInfo ();
    TypeInfo (const ID& id);
    TypeInfo (const TypeInfo& copy);

    /// @name ICloneable members.
    /// @{
    virtual TypeInfo* Clone () const;
    /// @}

    /// Getters
    const ID& GetID () const;
    const String& GetName () const;
    const float& GetTypeEffect (const ID& typeID);

    /// Setters
    void SetID (const ID& id);
    void SetName (const String& name);
    void AddTypeEffect (const ID& typeID, const float& effect);

  private:
    ID staticID_;
    String name_;
    collection::Map<ID, float> typeEffect_;

    static const float DEFAULT_FACTOR_EFFECT_VALUE;
  };
} // namespace yap

#endif // YAPOG_TYPEINFO_HPP
