#ifndef YAPOG_RECTREADER_HXX
# define YAPOG_RECTREADER_HXX

# include "YAPOG/System/StringHelper.hpp"
# include "YAPOG/System/Network/IPacket.hpp"
# include "YAPOG/System/IO/Xml/XmlReader.hpp"

namespace yap
{
  template <typename T>
  const String RectReader<T>::DEFAULT_XML_ROOT_NODE_NAME = "Rect";

  template <typename T>
  inline RectReader<T>::RectReader (sf::Rect<T>& rect)
    : rect_ (rect)
    , xmlRootNodeName_ (DEFAULT_XML_ROOT_NODE_NAME)
  {
  }

  template <typename T>
  inline RectReader<T>::RectReader (
    sf::Rect<T>& rect,
    const String& xmlRootNodeName)
    : rect_ (rect)
    , xmlRootNodeName_ (xmlRootNodeName)
  {
  }

  template <typename T>
  inline RectReader<T>::~RectReader ()
  {
  }

  template <typename T>
  inline void RectReader<T>::Visit (XmlReader& visitable)
  {
    String data = visitable.ReadString (xmlRootNodeName_);
    collection::Array<String> result;
    StringHelper::Split (data, ",", result);

    rect_.left = StringHelper::Parse<T> (result[0]);
    rect_.top = StringHelper::Parse<T> (result[1]);
    rect_.width = StringHelper::Parse<T> (result[2]);
    rect_.height = StringHelper::Parse<T> (result[3]);
  }

  template <typename T>
  inline void RectReader<T>::Visit (IPacket& visitable)
  {
    // Does nothing.
    // Unable to Read<T> from IReader.
    // Implemented in specializations.
  }

  template <>
  inline void RectReader<float>::Visit (IPacket& visitable)
  {
    rect_.left = visitable.ReadFloat ();
    rect_.top = visitable.ReadFloat ();
    rect_.width = visitable.ReadFloat ();
    rect_.height = visitable.ReadFloat ();
  }
} // namespace yap

#endif // YAPOG_RECTREADER_HXX
