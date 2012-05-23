#include "YAPOG/Game/Chat/ChatDisplayer.hpp"
#include "YAPOG/Game/Chat/ChatCommand.hpp"

namespace yap
{
  ChatDisplayer::ChatDisplayer ()
    : offset_ (0)
    , buff_ (*(new  collection::Array<String> ()))
    , chans_ ()
  {
    chans_.Add(new CMType ()); // Global, White
    chans_.Add(new CMType ("Group", "Green"));
    chans_.Add(new CMType ("Business", "Blue"));
    chans_.Add(new CMType ("Info", "Yellow"));
    chans_.Add(new CMType ("MP", "Purple"));
  }

  ChatDisplayer::~ChatDisplayer ()
  {
    ChansType::ItType it (chans_.Begin ());
    ChansType::ItType ite (chans_.End ());

    for (; it < ite; it++)
      delete (*it);
  }

  UInt32              ChatDisplayer::GetChanNb ()
  {
    return chans_.Count ();
  }

  /*
  void								ChatDisplayer::Display(ChatManagerType* c)
  {
    ChatCommand cc;
    String strToDisp = cc.ExecCmd(this, c);

    chans_[c->ChanNb]->Buff.Add(strToDisp);
    std::cout << chans_[c->ChanNb]->Name 
      << " (" << chans_[c->ChanNb]->Color 
      << ") :: "<< strToDisp << std::endl;
  }
  */
  String               ChatDisplayer::GetLastStrChan (Int32 c)
  {
    return (chans_[c]->Name 
      + " (" + chans_[c]->Color
      + ") :: "
      + chans_[c]->Buff[chans_[c]->Buff.Count ()]);
  }

  void                AddToBuff (size_t* off,
                                 ChatDisplayer::ChanBuf b,
                                 String s)
  {
    b.Add(s);
    (*off)++;
  }

  void                ChatDisplayer::AddToChan (Int32 c, String s)
  {
    CMType* mychan = chans_[c];
    UInt32 mychannb = mychan->Buff.Count ();
    size_t* mychanoff = &(mychan->Offset);
    BufferType* mychanbuf = &(mychan->Buff);

    if (mychannb < CHANMAXBUF) AddToBuff (mychanoff, *mychanbuf, s);
    else chans_[c]->Buff[chans_[c]->Offset] = s;

    String strtoadd = GetLastStrChan (c);

    if (buff_.Count () < CHANMAXBUF) AddToBuff (&offset_, buff_, strtoadd);
    else buff_[offset_++] = strtoadd;
    if (offset_ == CHANMAXBUF) offset_ = 0;
    if (chans_[c]->Offset == CHANMAXBUF) chans_[c]->Offset = 0;
  }

  void                ChatDisplayer::DisplayChan (Int32 c)
  {
    for (size_t i = 0; i < chans_[c]->Buff.Count (); i++)
      std::cout << chans_[c]->Name
      << " (" << chans_[c]->Color
      << ") :: " << chans_[c]->Buff[i] << std::endl;
  }

  void                ChatDisplayer::Display ()
  {
  }
} // namespace yap
