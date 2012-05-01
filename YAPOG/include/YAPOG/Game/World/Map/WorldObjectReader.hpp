#ifndef YAPOG_WORLDOBJECTREADER_HPP
# define YAPOG_WORLDOBJECTREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/IReaderVisitor.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class WorldObject;

  class WorldObjectReader : public IReaderVisitor
  {
      DISALLOW_COPY(WorldObjectReader);

    public:

      virtual ~WorldObjectReader ();

      virtual void Visit (XmlReader& visitable);

    protected:

      WorldObjectReader (
        WorldObject& worldObject,
        const String& xmlRootNodeName);

      String xmlRootNodeName_;

    private:

      WorldObject& worldObject_;
  };
} // namespace yap

#endif // YAPOG_WORLDOBJECTREADER_HPP
