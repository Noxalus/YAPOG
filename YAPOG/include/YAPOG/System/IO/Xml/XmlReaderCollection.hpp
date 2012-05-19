#ifndef YAPOG_XMLREADERCOLLECTION_HPP
# define YAPOG_XMLREADERCOLLECTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/List.hpp"
# include "YAPOG/System/IO/Xml/XmlReader.hpp"

namespace yap
{
  class YAPOG_LIB XmlReaderCollection
  {
      DISALLOW_COPY(XmlReaderCollection);

      typedef collection::List<XmlReaderPtrType>::ConstItType ConstItType;

    public:

      XmlReaderCollection ();
      ~XmlReaderCollection ();

      void Add (const XmlReaderPtrType& data);

      ConstItType begin () const;
      ConstItType end () const;

    private:

      collection::List<XmlReaderPtrType> data_;
  };
} // namespace yap

#endif // YAPOG_XMLREADERCOLLECTION_HPP
