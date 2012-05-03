#ifndef YAPOG_SPRITESETREADER_HXX
# define YAPOG_SPRITESETREADER_HXX

#include "YAPOG/Graphics/Game/Sprite/SpriteSet.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReaderCollection.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/System/StringHelper.hpp"

namespace yap
{
  template <typename K>
  inline SpriteSetReader<K>::SpriteSetReader (
    SpriteSet<K>& spriteSet,
    const String& xmlRootNodeName)
    : BaseSpriteReader (spriteSet, xmlRootNodeName)
    , spriteSet_ (spriteSet)
  {
  }

  template <typename K>
  inline SpriteSetReader<K>::~SpriteSetReader ()
  {
  }

  template <typename K>
  inline void SpriteSetReader<K>::Visit (XmlReader& visitable)
  {
    BaseSpriteReader::Visit (visitable);

    if (!visitable.TryChangeRoot (xmlRootNodeName_))
      YAPOG_THROW("Failed to read `" + xmlRootNodeName_ + "' node.");

    XmlReaderCollection spriteReaders;
    visitable.ReadNodes ("sprite", spriteReaders);
    for (auto& spriteReader : spriteReaders)
    {
      K key = StringHelper::Parse<K> (spriteReader->ReadString ("key"));

      String spriteType = spriteReader->ReadString ("spriteType");

      spriteSet_.AddSprite (
        key,
        ObjectFactory::Instance ().Create<ISprite> (
          spriteType,
          *spriteReader,
          spriteType));
    }

    visitable.UpChangeRoot ();
  }
} // namespace yap

#endif // YAPOG_SPRITESETREADER_HXX
