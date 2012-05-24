#ifndef YAPOG_BOUNDINGBOXREADER_HPP
# define YAPOG_BOUNDINGBOXREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/BaseReaderVisitor.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class BoundingBox;

  class BoundingBoxReader : public BaseReaderVisitor
  {
      DISALLOW_COPY(BoundingBoxReader);

    public:

      BoundingBoxReader (
        BoundingBox& boundingBox,
        const String& xmlRootNodeName);
      virtual ~BoundingBoxReader ();

      virtual void Visit (XmlReader& visitable);

    protected:

      String xmlRootNodeName_;

    private:

      BoundingBox& boundingBox_;
  };
} // namespace yap

#endif // YAPOG_BOUNDINGBOXREADER_HPP
