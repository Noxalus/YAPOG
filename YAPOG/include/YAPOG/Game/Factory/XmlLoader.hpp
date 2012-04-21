#ifndef YAPOG_XMLLOADER_HPP
# define YAPOG_XMLLOADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Factory/ILoader.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/Path.hpp"

template <typename T>
namespace yap
{
  class XmlLoader : public ILoader<T>
  {
      DISALLOW_COPY(XmlLoader);

    public:

      virtual ~XmlLoader ();

      virtual T* Load (const ID& id);

    protected:

      XmlLoader (
        const Path& pathRoot,
        const String& rootNodeName);

      T& GetObject ();

      const Path pathRoot;
      const String rootNodeName_;

    private:

      virtual T* HandleLoad (const ID& id) = 0;

      collection::Map<ID, T*> objects_;
      ID currentID_;
      T* currentObject_;
  };
} // namespace yap

# include "YAPOG/Game/Factory/XmlLoader.hxx"

#endif // YAPOG_XMLLOADER_HPP
