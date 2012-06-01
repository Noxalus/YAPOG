#ifndef YAPOG_MATRIX_HPP
# define YAPOG_MATRIX_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Array.hpp"

namespace yap
{
  namespace collection
  {
    template <typename T>
    class Matrix
    {
      public:

        typedef T DataType;
        typedef Array<DataType> InnerType;
        typedef typename InnerType::SizeType SizeType;
        typedef typename InnerType::ItType ItType;
        typedef typename InnerType::ConstItType ConstItType;

        Matrix (SizeType width, SizeType height, const DataType& data);

        Matrix (const Matrix<T>& copy);
        Matrix& operator= (const Matrix<T>& copy);

        ItType begin ();
        ConstItType begin () const;
        ItType Begin ();
        ConstItType Begin () const;

        ItType end ();
        ConstItType end () const;
        ItType End ();
        ConstItType End () const;

        void Resize (SizeType x, SizeType y, const T& data);

        void Set (SizeType x, SizeType y, const T& data);

        const T& operator() (SizeType x, SizeType y) const;
        T& operator() (SizeType x, SizeType y);

      private:

        SizeType GetIndex (SizeType x, SizeType y) const;

        SizeType width_;
        SizeType height_;

        InnerType data_;
    };
  } // namespace collection
} // namespace yap

# include "YAPOG/Collection/Matrix.hxx"

#endif // YAPOG_MATRIX_HPP
