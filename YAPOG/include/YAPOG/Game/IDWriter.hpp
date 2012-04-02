#ifndef YAPOG_IDWRITER_HPP
# define YAPOG_IDWRITER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/IWriterVisitor.hpp"

namespace yap
{
  class ID;

  class IDWriter : public IWriterVisitor
  {
    public:

      IDWriter (const ID& id);
      virtual ~IDWriter ();

      virtual void Visit (XmlWriter& visitable);
      virtual void Visit (DebugLogger& visitable);

    private:

      const ID& id_;
  };
} // namespace yap

#endif // YAPOG_IDWRITER_HPP
