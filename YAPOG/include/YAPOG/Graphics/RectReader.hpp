#ifndef YAPOG_RECTREADER_HPP
# define YAPOG_RECTREADER_HPP

# include <SFML/Graphics/Rect.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/IReaderVisitor.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  template <typename T>
  class RectReader : public IReaderVisitor
  {
      DISALLOW_COPY(RectReader);

    public:

      explicit RectReader (sf::Rect<T>& rect);
      RectReader (sf::Rect<T>& rect, const String& xmlRootNodeName);
      virtual ~RectReader ();

      virtual void Visit (XmlReader& visitable);

    private:

      static const String DEFAULT_XML_ROOT_NODE_NAME;

      sf::Rect<T>& rect_;

      String xmlRootNodeName_;
  };
} // namespace yap

# include "YAPOG/Graphics/RectReader.hxx"

#endif // YAPOG_RECTREADER_HPP
