#ifndef YAPOG_XMLTREE_HPP
# define YAPOG_XMLTREE_HPP

# include <memory>

# include <boost/property_tree/xml_parser.hpp>
# include <boost/property_tree/ptree.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/IOStream.hpp"

namespace yap
{
  class XmlTree;
  typedef std::shared_ptr<XmlTree> XmlTreePtrType;

  class YAPOG_LIB XmlTree
  {
      DISALLOW_ASSIGN(XmlTree);

    public:

      typedef boost::property_tree::ptree DataType;

      XmlTree ();
      XmlTree (const XmlTree& copy);

      template <typename T>
      const T Get (const String& name) const;

      template <typename T>
      const T Get () const;

      template <typename T>
      void Add (const String& name, const T& value);

      void Create (const String& rootName);
      void CreateFromStream (IStream& iStream, const String& rootName);

      void CreateFromXmlTree (const String& rootName, XmlTree& copy);
/*      void CreateFromRawData (
        const String& rootName,
        XmlTree& rootSource,
        DataType* data);*/

      /// @todo Enhance writing settings management.
      void Dump (OStream& oStream);


//      void UpChangeRoot ();
//      void DownChangeRoot (const String& name);
//      bool TryChangeRoot (const String& name);

      XmlTreePtrType ChangeRoot (const String& rootName);

      bool NodeExists (const String& name) const;

      const String& GetNode (int index) const;

      DataType* GetRootRawData () const;

    private:

//      void AbsoluteChangeRoot (const String& rootName);

      DataType& GetChild (const String& name);
      DataType& AbsoluteGetChild (const String& name);

      DataType& GetRootData ();
      const DataType& GetRootData () const;

//      void SetAbsoluteRootName (const String& rootName);
//      void AppendRootNodeName (const String& nodeName);
//      void UpdateRelativeRootName ();

      DataType rootData_;
      DataType* data_;
//      DataType* rootDataPtr_;

//      String currentAbsoluteRootName_;
//      String currentRelativeRootName_;
  };
} // namespace yap

# include "YAPOG/System/IO/Xml/XmlTree.hxx"

#endif // YAPOG_XMLTREE_HPP
