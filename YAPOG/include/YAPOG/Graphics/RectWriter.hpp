#ifndef YAPOG_RECTWRITER_HPP
# define YAPOG_RECTWRITER_HPP

# include <SFML/Graphics/Rect.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/BaseWriterVisitor.hpp"

namespace yap
{
  template <typename T>
  class YAPOG_LIB RectWriter : public BaseWriterVisitor
  {
      DISALLOW_COPY(RectWriter);

    public:

      explicit RectWriter (const sf::Rect<T>& rect);
      virtual ~RectWriter ();

      virtual void Visit (XmlWriter& visitable);
      virtual void Visit (IPacket& visitable);

    private:

      const sf::Rect<T>& rect_;
  };
} // namespace yap

# include "YAPOG/Graphics/RectWriter.hxx"

#endif // YAPOG_RECTWRITER_HPP
