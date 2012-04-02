#ifndef YAPOG_ARRAY_HPP
# define YAPOG_ARRAY_HPP

# include <vector>

# include "YAPOG/Macros.hpp"

namespace yap
{
  namespace collection
  {
    /// @brief Wrapper for std::vector.
    template <typename T>
    class YAPOG_LIB Array
    {
      public:

        typedef T DataType;
        typedef std::vector<DataType> InnerType;
        typedef typename InnerType::size_type SizeType;
        typedef typename InnerType::iterator ItType;
        typedef typename InnerType::const_iterator ConstItType;

        /// @brief Constructs an empty Array.
        Array ();

        /// @brief Constructs an Array from another one with the same size
        /// and a copy of each element of the source Array.
        /// @param copy Source Array for the copy.
        Array (const Array<T>& copy);
        /// @brief Copies the source Array to this Array.
        /// @param copy Source Array for the copy.
        Array& operator= (const Array<T>& copy);

        ItType begin ();
        ConstItType begin () const;
        ItType Begin ();
        ConstItType Begin () const;

        ItType end ();
        ConstItType end () const;
        ItType End ();
        ConstItType End () const;

        void Add (const T& data);
        void Add (const Array<T>& data);

        bool Contains (const T& data) const;
        bool Contains (const Array<T>& data) const;

        void Remove (const T& data);
        void RemoveBack ();

        void Clear ();

        bool IsEmpty () const;
        SizeType Count () const;

        const T& operator[] (SizeType index) const;
        T& operator[] (SizeType index);

      private:

        InnerType data_;
    };
  } // namespace collection
} // namespace yap

# include "YAPOG/Collection/Array.hxx"

#endif // YAPOG_ARRAY_HPP
