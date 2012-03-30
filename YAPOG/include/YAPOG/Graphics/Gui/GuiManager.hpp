#ifndef YAPOG_GUIMANAGER_HPP
# define YAPOG_GUIMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/IGuiManager.hpp"
# include "YAPOG/Graphics/SpatialInfo.hpp"

namespace yap
{
  class GuiManager : public IGuiManager
  {
    public:

      GuiManager ();
      virtual ~GuiManager ();

      /// @name IDrawable members.
      /// @{
      virtual void Draw (IDrawingContext& context);
      /// @}

      /// @name IEventHandler members.
      /// @{
      virtual bool OnEvent (const GuiEvent& guiEvent);
      /// @}

      /// @name IUdpdatable members.
      /// @{
      virtual void Update (const Time& dt);
      /// @}

      /// @name ISpatial members.
      /// @{
      virtual const Vector2& GetPosition () const;
      virtual const Vector2& GetSize () const;

      virtual const Vector2& GetTopLeft () const;
      virtual const Vector2& GetBottomRight () const;
      virtual const Vector2& GetCenter () const;

      virtual const sf::FloatRect& GetRectangle () const;

      virtual void Move (const Vector2& offset);
      virtual void Scale (const Vector2& factor);
      /// @}

    private:

      SpatialInfo spatialInfo_;
  };
} // namespace yap

#endif // YAPOG_GUIMANAGER_HPP
