#ifndef YAPOG_GAMEMESSAGE_HPP
# define YAPOG_GAMEMESSAGE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class YAPOG_LIB GameMessage
  {
      DISALLOW_COPY(GameMessage);

    public:

      GameMessage ();
      ~GameMessage ();

      const String& GetContent () const;
      const String& GetSenderName () const;

      void SetContent (const String& content);
      void SetSenderName (const String& senderName);

    private:

      String content_;
      String senderName_;
  };
} // namespace yap

#endif // YAPOG_GAMEMESSAGE_HPP
