#ifndef YAPOG_RECTWRITER_HXX
# define YAPOG_RECTWRITER_HXX

# include "YAPOG/System/StringHelper.hpp"
# include "YAPOG/System/Network/IPacket.hpp"
# include "YAPOG/System/IO/Xml/XmlWriter.hpp"

namespace yap
{
  template <typename T>
  inline RectWriter<T>::RectWriter (const sf::Rect<T>& rect)
    : BaseWriterVisitor ()
    , rect_ (rect)
  {
  }

  template <typename T>
  inline RectWriter<T>::~RectWriter ()
  {
  }

  template <typename T>
  inline void RectWriter<T>::Visit (XmlWriter& visitable)
  {
    /// @todo
  }

  template <typename T>
  inline void RectWriter<T>::Visit (IPacket& visitable)
  {
    visitable.Write (rect_.left);
    visitable.Write (rect_.top);
    visitable.Write (rect_.width);
    visitable.Write (rect_.height);
  }
} // namespace yap

#endif // YAPOG_RECTWRITER_HXX
