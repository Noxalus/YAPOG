#ifndef YAPOG_MAP_HPP
# define YAPOG_MAP_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Game/Factory/IIDLoadable.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  /// @brief Base Map class for both client and server.
  class YAPOG_LIB Map : public IIDLoadable
  {
      DISALLOW_ASSIGN(Map);

    public:

      Map (const ID& id);
      virtual ~Map ();

      const ID& GetID () const;
      void SetID (const ID& id);

      const String& GetName () const;
      void SetName (const String& name);

      const uint& GetWidth () const;
      const uint& GetHeight () const;
      void SetSize (uint width, uint height);

    protected:

      Map (const Map& copy);

    private:

      virtual void HandleSetSize (uint width, uint height);

      static const String DEFAULT_NAME;
      static const uint DEFAULT_WIDTH;
      static const uint DEFAULT_HEIGHT;

      ID id_;
      String name_;

      uint width_;
      uint height_;
  };
} // namespace yap

#endif // YAPOG_MAP_HPP
