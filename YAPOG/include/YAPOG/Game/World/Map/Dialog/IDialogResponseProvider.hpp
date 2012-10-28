#ifndef YAPOG_IDIALOGRESPONSEPROVIDER_HPP
# define YAPOG_IDIALOGRESPONSEPROVIDER_HPP

# include "YAPOG/Game/ID.hpp"
# include "YAPOG/Collection/Array.hpp"

namespace yap
{
  struct IDialogResponse;

  struct IDialogResponseProvider
  {
      virtual ~IDialogResponseProvider () { }

      virtual const collection::Array<IDialogResponse*>&
      GetResponses () const = 0;

      virtual IDialogNode& GetNextNode (const ID& responseID) = 0;
  };
} // namespace yap

#endif // YAPOG_IDIALOGRESPONSEPROVIDER_HPP
