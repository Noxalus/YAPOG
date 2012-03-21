#ifndef YAPOG_XMLTREE_HPP
# define YAPOG_XMLTREE_HPP

# include <boost/property_tree/xml_parser.hpp>
# include <boost/property_tree/ptree.hpp>

# include "YAPOG/Export.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/IOStream.hpp"

namespace yap
{
  class YAPOG_LIB XmlTree
  {
    public:

      XmlTree ();

      template <typename T>
      const T Get (const String& name) const;

      template <typename T>
      void Add (const String& name, const T& value);

      void Create (const String& rootName);
      void CreateFromStream (IStream& iStream, const String& rootName);
      void Dump (OStream& oStream);

      void ChangeRoot (const String& rootName);

    private:

      boost::property_tree::ptree rootData_;
      boost::property_tree::ptree* data_;
  };
} /// namespace yap

# include "YAPOG/System/IO/Xml/XmlTree.hxx"

#endif /// !YAPOG_XMLTREE_HPP
