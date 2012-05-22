#include "YAPOG/Game/Chat/ChatDisplayer.hpp"
#include "YAPOG/Game/Chat/ChatCommand.hpp"

namespace yap
{
  ChatDisplayer::ChatDisplayer()
  {
    chans_.Add(new CMType ()); // Global, White
    chans_.Add(new CMType ("Group", "Green"));
    chans_.Add(new CMType ("Business", "Blue"));
    chans_.Add(new CMType ("Info", "Yellow"));
    chans_.Add(new CMType ("MP", "Purple"));
  }

  ChatDisplayer::~ChatDisplayer()
  {
    ChansType::ItType it (chans_.Begin());
    ChansType::ItType ite (chans_.End());

    for (; it < ite; it++)
      delete (*it);
  }

  UInt32              ChatDisplayer::GetChanNb()
  {
    return chans_.Count();
  }

  void								ChatDisplayer::Display(ChatManagerType* c)
  {
    ChatCommand cc;
    String strToDisp = cc.ExecCmd(this, c);
    chans_[c->ChanNb]->Buff.Add(strToDisp);
    std::cout << chans_[c->ChanNb]->Name 
              << " (" << chans_[c->ChanNb]->Color 
              << ") :: "<< strToDisp << std::endl;
  }
} // namespace yap
