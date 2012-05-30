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
    : offset_ (0)
    , buff_ ()
    , chans_ ()
    , output_ ()
    //, chanbooltab_ (NBCHAN, false)
    , chanbooltab_ (new bool[NBCHAN])
  {
    chans_.Add(new CMType ()); // System, Red
    chans_.Add(new CMType ("Global", "White"));
    chans_.Add(new CMType ("Group", "Green"));
    chans_.Add(new CMType ("Business", "Blue"));
    chans_.Add(new CMType ("Info", "Yellow"));  
    chans_.Add(new CMType ("MP", "Purple"));

    InitTab (&chanbooltab_, NBCHAN, false);
    output_ = std::make_pair (chans_[0], "");
  }

  ChatDisplayer::ChatDisplayer (UInt32 c)
    : offset_ (0)
    , buff_ ()
    , chans_ ()
    , output_ ()
    //, chanbooltab_ (NBCHAN, false)
    , chanbooltab_ (new bool[NBCHAN])
  {
    chans_.Add(new CMType ()); // System, Red
    chans_.Add(new CMType ("Global", "White"));
    chans_.Add(new CMType ("Group", "Green"));
    chans_.Add(new CMType ("Business", "Blue"));
    chans_.Add(new CMType ("Info", "Yellow"));  
    chans_.Add(new CMType ("MP", "Purple"));

    output_ = std::make_pair (chans_[0], "");
    InitTab (&chanbooltab_, NBCHAN, false);
    chanbooltab_[c] = true;
  }
  
  //ChatDisplayer::ChatDisplayer (ChansBoolType chanbooltab)
  //  : offset_ (0)
  //  , buff_ ()
  //  , chans_ ()
  //  , output_ ()
  //  , chanbooltab_ (chanbooltab)
  //{
  //  chans_.Add(new CMType ()); // System, Red
  //  chans_.Add(new CMType ("Global", "White"));
  //  chans_.Add(new CMType ("Group", "Green"));
  //  chans_.Add(new CMType ("Business", "Blue"));
  //  chans_.Add(new CMType ("Info", "Yellow"));  
  //  chans_.Add(new CMType ("MP", "Purple"));

  //  output_ = std::make_pair (chans_[0], "");
  //}

  ChatDisplayer::~ChatDisplayer ()
  {
    ChansType::ItType it (chans_.Begin ());
    ChansType::ItType ite (chans_.End ());

    for (; it < ite; it++)
      delete (*it);

    delete (chanbooltab_);
  }

  UInt32              ChatDisplayer::GetChanNb ()
  {
    return chans_.Count ();
  }

  String              ChatDisplayer::GetLastStrChan (UInt32 c)
  {
    CMType* cmt = buff_[c].first;
    String* str = &buff_[c].second;

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

  void                ChatDisplayer::DisplayChan ()
  {
    size_t size = buff_.Count ();
    size_t i = 0;

    if (size < CHANMAXBUF)
      MyDisplay (i, size);
    else
    {
      size_t index = offset_ + 1;
      MyDisplay (index, size);
      MyDisplay (i, index);
    }
  }

  void                ChatDisplayer::Display ()
  {
    if (!output_.second.empty ())
      DISPLAYS (output_.first->Name
      + " (" + output_.first->Color
      + ") :: " + output_.second);
  }
} // namespace yap
