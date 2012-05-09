#ifndef YAPOG_BASESPRITEREADER_HPP
# define YAPOG_BASESPRITEREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/BaseReaderVisitor.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class BaseSprite;

  class YAPOG_LIB BaseSpriteReader : public BaseReaderVisitor
  {
      DISALLOW_COPY(BaseSpriteReader);

    public:

      BaseSpriteReader (BaseSprite& baseSprite, const String& xmlRootNodeName);
      virtual ~BaseSpriteReader ();

      virtual void Visit (XmlReader& visitable);

    protected:

      String xmlRootNodeName_;

    private:

      BaseSprite& baseSprite_;
  };
} // namespace yap

#endif // YAPOG_BASESPRITEREADER_HPP
