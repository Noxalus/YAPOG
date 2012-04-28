#ifndef YAPOG_XMLTREE_HPP
# define YAPOG_XMLTREE_HPP

# include <boost/property_tree/xml_parser.hpp>
# include <boost/property_tree/ptree.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/IOStream.hpp"

namespace yap
{
  class YAPOG_LIB XmlTree
  {
      DISALLOW_COPY(XmlTree);

    public:

      typedef boost::property_tree::ptree DataType;

      XmlTree ();

      template <typename T>
      const T Get (const String& name) const;

      template <typename T>
      const T Get () const;

      template <typename T>
      void Add (const String& name, const T& value);

      void Create (const String& rootName);
      void CreateFromStream (IStream& iStream, const String& rootName);

      void CreateFromXmlTree (const XmlTree& copy);
      void CreateFromRawData (DataType* data);

      /// @todo Enhance writing settings management.
      void Dump (OStream& oStream);

      void AbsoluteChangeRoot (const String& rootName);
      void UpChangeRoot ();
      void DownChangeRoot (const String& name);
      bool TryChangeRoot (const String& name);

      bool NodeExists (const String& name) const;

      const String& GetNode (int index) const;

      DataType* GetRootRawData () const;

    private:

      void SetAbsoluteRootName (const String& rootName);
      void UpdateRelativeRootName ();

      DataType rootData_;
      DataType* data_;

      String currentAbsoluteRootName_;
      String currentRelativeRootName_;
  };
} // namespace yap

# include "YAPOG/System/IO/Xml/XmlTree.hxx"

#endif // YAPOG_XMLTREE_HPP
