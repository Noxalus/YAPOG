#include "YAPOG/Game/Chat/ChatDisplayer.hpp"
#include "YAPOG/Game/Chat/ChatCommand.hpp"

namespace yap
{
  ChatDisplayer::ChatDisplayer()
  {
    chans_.Add(new CMType ());
    chans_.Add(new CMType ("Group", "Green"));
    chans_.Add(new CMType ("Business", "Blue"));
    chans_.Add(new CMType ("Info", "Yellow"));
  }

  ChatDisplayer::~ChatDisplayer()
  {
    ChansType::ItType it (chans_.Begin());
    ChansType::ItType ite (chans_.End());

    for (; it < ite; it++)
      delete (*it);
  }

  ChatDisplayer::ChanManager::ChanManager()
  {
    Name = "Global";
    Color = "White";
  }

  ChatDisplayer::ChanManager::ChanManager(String name,
                                          String color)
  {
    Name = name;
    Color = color;
  }

  void								ChatDisplayer::Display(ChatManagerType* c)
  {
    ChatCommand cc;
    String strToDisp = cc.ExecCmd(this, c);
    chans_[c->ChanNb]->Buff.Add(strToDisp);
    std::cout << c->ChanNb << " (" << chans_[c->ChanNb]->Color << ") :: "<< strToDisp << std::endl;
  }
} // namespace yap
