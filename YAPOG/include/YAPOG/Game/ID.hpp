#ifndef YAPOG_ID_HPP
# define YAPOG_ID_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class ID
  {
    public:

      typedef UInt64 ValueType;

      ID ();
      explicit ID (ValueType value);

      const ValueType& Value () const;
      void ChangeValue (ValueType value);

      bool operator== (const ID& right);
      bool operator!= (const ID& right);
      bool operator> (const ID& right);
      bool operator< (const ID& right);
      bool operator>= (const ID& right);
      bool operator<= (const ID& right);

    private:

      static const ValueType DEFAULT_VALUE;

      ValueType value_;
  };
} // namespace yap

#endif // YAPOG_ID_HPP
