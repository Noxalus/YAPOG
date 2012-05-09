#ifndef YAPOG_SELECTACCOUNT_HPP
# define YAPOG_SELECTACCOUNT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Database/DatabaseManager.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/System/String.hpp"
# include "Account/Account.hpp"

class SelectAccount
{
  DISALLOW_COPY(SelectAccount);

public:
  SelectAccount (
    yap::DatabaseManager& dm, 
    const yap::String& name,
    Account& account);

  void DisplayData ();
  bool IsLogged ();
};

#endif // YAPOG_SELECTACCOUNT_HPP