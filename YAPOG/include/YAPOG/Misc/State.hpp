#ifndef YAPOG_STATE_HPP
# define YAPOG_STATE_HPP

namespace yap
{
  /// @class State
  /// @brief Wrapper for a type that represents an object state.
  template <typename T>
  class State
  {
    public:

      State ();
      State (const T& value);

      State (const State<T>& copy);
      State& operator= (const State<T>& copy);

      bool operator== (const State<T>& rhs) const;
      bool operator== (const T& rhs) const;

      bool operator!= (const State<T>& rhs) const;
      bool operator!= (const T& rhs) const;

      operator const T& () const;

    private:

      T value_;
  };

  template <typename T>
  bool operator== (const T& lhs, const State<T>& rhs);
} /// namespace yap

# include "YAPOG/Misc/State.hxx"

#endif /// !YAPOG_STATE_HPP
