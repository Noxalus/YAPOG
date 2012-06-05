#include "YAPOG/Game/Chat/ChatDisplayer.hpp"
#include "YAPOG/Game/Chat/ChatCommand.hpp"

namespace yap
{
  void InitTab (bool** tab, size_t size, bool value)
  {
    for (size_t i = 0; i < size; i++)
      (*tab)[i] = false;
  }

  ChatDisplayer::ChatDisplayer ()
    : name_ ("Systeme")
    , offset_ (0)
    , buff_ ()
    , chans_ ()
    , output_ ()
    //, chanbooltab_ (NBCHAN, false)
    , chanbooltab_ (new bool[NBCHAN])
  {
    chans_.Add (new CMType ()); // System, Red
    chans_.Add (new CMType ("Global", "Black", 1));
    chans_.Add (new CMType ("Group", "Green", 2));
    chans_.Add (new CMType ("Business", "Blue", 3));
    chans_.Add (new CMType ("Info", "Yellow", 4));  
    chans_.Add (new CMType ("MP", "Purple", 5));

    InitTab (&chanbooltab_, NBCHAN, false);
    output_ = std::make_pair (chans_[0], "");
  }

  ChatDisplayer::ChatDisplayer (String name, UInt32 c)
    : name_ (name)
    , offset_ (0)
    , buff_ ()
    , chans_ ()
    , output_ ()
    , chanbooltab_ (new bool[NBCHAN])
  {
    chans_.Add (new CMType ()); // System, Red
    chans_.Add (new CMType ("Global", "Black", 1));
    chans_.Add (new CMType ("Group", "Green", 2));
    chans_.Add (new CMType ("Business", "Blue", 3));
    chans_.Add (new CMType ("Info", "Yellow", 4));  
    chans_.Add (new CMType ("MP", "Purple", 5));

    output_ = std::make_pair (chans_[0], "");
    chanbooltab_[c] = true;
  }

  ChatDisplayer::ChatDisplayer (String name, bool* chanbooltab)
    : name_ (name)
    , offset_ (0)
    , buff_ ()
    , chans_ ()
    , output_ ()
    , chanbooltab_ (new bool[NBCHAN])
  {
    chans_.Add (new CMType ()); // System, Red
    chans_.Add (new CMType ("Global", "Black", 1));
    chans_.Add (new CMType ("Group", "Green", 2));
    chans_.Add (new CMType ("Business", "Blue", 3));
    chans_.Add (new CMType ("Info", "Yellow", 4));  
    chans_.Add (new CMType ("MP", "Purple", 5));

    output_ = std::make_pair (chans_[0], "");
    for (size_t i = 0; i < NBCHAN; i++)
      chanbooltab_[i] = chanbooltab[i];
  }

  ChatDisplayer::~ChatDisplayer ()
  {
    ChansType::ItType it (chans_.Begin ());
    ChansType::ItType ite (chans_.End ());

    for (; it < ite; it++)
    {
      delete (*it);
      *it = nullptr;
    }

    delete chanbooltab_;
    chanbooltab_ = nullptr;
  }

  UInt32              ChatDisplayer::GetChanNb ()
  {
    return chans_.Count ();
  }

  String              ChatDisplayer::GetLastStrChan ()
  {
    if (buff_.Count () == 0)
      return "";

    size_t size = buff_.Count ();
    CMType* cmt = buff_[size - 1].first;
    String* str = &buff_[size - 1].second;

    return (cmt->Name 
      + " (" + cmt->Color
      + ") :: "
      + *str);
  }

  void                ChatDisplayer::AddChan (UInt32 c)
  {
    if (c >= 0 && c <= NBCHAN)
      chanbooltab_[c] = true;
  }

  void                ChatDisplayer::RmChan (UInt32 c)
  {
    if (c >= 0 && c <= NBCHAN)
      chanbooltab_[c] = false;
  }

  void                ChatDisplayer::DisplayChanOn ()
  {
    for (int i = 0; i < NBCHAN; i++)
      DISPLAYS ("Chan " + StringHelper::ToString (i) 
      + " is "
      + (chanbooltab_[i] ? "ON" : "OFF"));
  }

  void                ChatDisplayer::AddToChan (Int32 c, BufferType b)
  {
    output_ = std::make_pair (chans_[0], "");
    if (chanbooltab_[c] == true)
    {
      CMType* mychan = chans_[c];
      String  strtoadd = "";

      for (size_t i = 0; i < b.Count (); i++)
      {
        String s = b[i];

        strtoadd += + ((i == 0) ? "" : " ") + s;

        if (buff_.Count () < CHANMAXBUF)
        {
          buff_.Add (std::make_pair (mychan, s));
          offset_++;
        }
        else
          buff_[offset_++] = std::make_pair (mychan, s);
        if (offset_ == CHANMAXBUF)
          offset_ = 0;
      }
      output_ = std::make_pair (mychan, strtoadd);
    }
  }

  void                ChatDisplayer::MyDisplay (size_t index, size_t last)
  {
    for (size_t i = index; i < last ; i++)
      DISPLAYS (buff_[i].first->Name
      + " (" + buff_[i].first->Color
      + ") :: " + buff_[i].second);
  }

  
  void                ChatDisplayer::MyDisplayAdder (size_t index,
    size_t last,
    ResponseType* rt)
  {
    MyDisplay (index, last);
    for (size_t i = index; i < last ; i++)
      rt->Add (std::make_pair (buff_[i].first->ChanNb, buff_[i].second));
  }

  ResponseType        ChatDisplayer::DisplayTab (ChatDisplayer* cd)
  {
    size_t size = buff_.Count ();
    size_t i = 0;
    ResponseType rt;
    String switchstr = cd->GetLastStrChan ();
    
    rt.Clear ();
    if (!switchstr.empty ())
      rt.Add (std::make_pair (0, (cd->GetLastStrChan ())));
    if (size < CHANMAXBUF)
      MyDisplayAdder (i, size, &rt);
    else
    {
      size_t index = offset_ + 1;
      MyDisplayAdder (index, size, &rt);
      MyDisplayAdder (i, index, &rt);
    }

    return rt;
  }

  ResponseType        ChatDisplayer::Display ()
  {
    ResponseType rt;

    rt.Clear ();
    if (!output_.second.empty ())
    {
      DISPLAYS (output_.first->Name
        + " (" + output_.first->Color
        + ") :: " + output_.second);
      rt.Add (std::make_pair (output_.first->ChanNb, output_.second));
    }

    return rt;
  }

  String              ChatDisplayer::GetName ()
  {
    return name_;
  }

  ChanBufType         ChatDisplayer::GetBuff ()
  {
    return buff_;
  }
} // namespace yap
