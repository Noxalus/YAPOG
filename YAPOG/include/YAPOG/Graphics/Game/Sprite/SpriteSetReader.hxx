#ifndef YAPOG_SPRITESETREADER_HXX
# define YAPOG_SPRITESETREADER_HXX

#include "YAPOG/Graphics/Game/Sprite/SpriteSet.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReaderCollection.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/System/StringHelper.hpp"

#include "YAPOG/System/IO/Log/DebugLogger.hpp"
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

    auto reader = visitable.ChangeRoot (xmlRootNodeName_);

    XmlReaderCollection spriteReaders;
    reader->ReadNodes ("sprite", spriteReaders);
    for (auto& spriteReader : spriteReaders)
    {
      K key = StringHelper::Parse<K> (spriteReader->ReadString ("key"));
      DebugLogger::Instance ().LogLine (spriteReader->ReadString ("key"));
      String spriteType = spriteReader->ReadString ("spriteType");

      spriteSet_.AddSprite (
        key,
        ObjectFactory::Instance ().Create<ISprite> (
          spriteType,
          *spriteReader,
          spriteType));
    }
  }
} // namespace yap

#endif // YAPOG_SPRITESETREADER_HXX
