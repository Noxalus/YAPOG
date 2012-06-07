#ifndef YAPOG_MAPEVENTQUEUE_HPP
# define YAPOG_MAPEVENTQUEUE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Queue.hpp"

namespace yap
{
  class MapEventContext;

  class MapEventQueue
  {
      DISALLOW_COPY(MapEventQueue);

    public:

      MapEventQueue ();

      void AddEvent (MapEventContext* event);
      MapEventContext& GetEvent ();

      bool IsEmpty () const;

    private:

      collection::Queue<MapEventContext*> events_;
  };
} // namespace yap

#endif // YAPOG_MAPEVENTQUEUE_HPP
