#ifndef YAPOG_IDREADER_HPP
# define YAPOG_IDREADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/IReaderVisitor.hpp"

namespace yap
{
  class ID;

  class IDReader : public IReaderVisitor
  {
    public:

      IDReader (ID& id);
      virtual ~IDReader ();

      virtual void Visit (XmlReader& visitable);

    private:

      ID& id_;
  };
} // namespace yap

#endif // YAPOG_IDREADER_HPP
