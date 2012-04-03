#ifndef YAPOG_GUIMANAGER_HPP
# define YAPOG_GUIMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/IGuiManager.hpp"
# include "YAPOG/Graphics/SpatialInfo.hpp"

namespace yap
{
  /// @brief Common implementation of root widget manager.
  /// @todo Implementation of the list of IWidgets
  /// and methods that maintain it.
  class YAPOG_LIB GuiManager : public IGuiManager
  {
      DISALLOW_COPY(GuiManager);

    public:

      GuiManager ();
      virtual ~GuiManager ();

      /// @name IDrawable members.
      /// @{
      virtual void Draw (IDrawingContext& context);

      virtual bool IsVisible () const;
      virtual void Show (bool isVisible);

      virtual void ChangeColor (const sf::Color color);
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

      static const bool DEFAULT_VISIBLE_STATE;

      SpatialInfo spatialInfo_;
      bool isVisible_;
  };
} // namespace yap

#endif // YAPOG_GUIMANAGER_HPP
