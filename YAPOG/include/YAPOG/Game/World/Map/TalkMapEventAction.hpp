#ifndef YAPOG_TALKMAPEVENTACTION_HPP
# define YAPOG_TALKMAPEVENTACTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/BaseMapEventAction.hpp"

namespace yap
{
  struct IDialogActor;

  class TalkMapEventAction : public BaseMapEventAction
  {
      DISALLOW_ASSIGN(TalkMapEventAction);

    public:

      TalkMapEventAction ();

      virtual ~TalkMapEventAction ();

      void SetSourceDialogActor (const IDialogActor& dialogActor);

      virtual void VisitPlayer (IPlayer& visitable);

      /// @name ICloneable members.
      /// @{
      virtual TalkMapEventAction* Clone () const;
      /// @}

    protected:

      TalkMapEventAction (const TalkMapEventAction& copy);

    private:

      const IDialogActor* sourceDialogActor_;
  };
} // namespace yap

#endif // YAPOG_TALKMAPEVENTACTION_HPP
