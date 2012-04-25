#ifndef YAPOG_ID_HPP
# define YAPOG_ID_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"

namespace yap
{
  class YAPOG_LIB ID
  {
    public:

      typedef UInt64 ValueType;

      ID ();
      explicit ID (ValueType value);

      ID (const ID& copy);
      ID& operator= (const ID& copy);

      const ValueType& GetValue () const;
      void SetValue (ValueType value);

<<<<<<< HEAD
      bool operator== (const ID& right) const;
      bool operator!= (const ID& right) const;
      bool operator> (const ID& right) const;
      bool operator< (const ID& right) const;
      bool operator>= (const ID& right) const;
      bool operator<= (const ID& right) const;

=======
      bool operator== (const ID& right);
      bool operator!= (const ID& right);
      bool operator> (const ID& right);
      bool operator< (const ID& right);
      bool operator>= (const ID& right);
      bool operator<= (const ID& right);
>>>>>>> 63750bb27bcf3a759bac1f1ae9b602fd642e4c15
    private:

      static const ValueType DEFAULT_VALUE;

      ValueType value_;
  };
} // namespace yap

#endif // YAPOG_ID_HPP
