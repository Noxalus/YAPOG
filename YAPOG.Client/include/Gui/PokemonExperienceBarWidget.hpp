#ifndef YAPOG_CLIENT_POKEMONEXPERIENCEBARWIDGET_HPP
# define YAPOG_CLIENT_POKEMONEXPERIENCEBARWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/ProgressBarWidget.hpp"

namespace yap
{
  class PictureBox;
  class HorizontalLayout;
  class PokemonExperience;
}

namespace ycl
{
  class PokemonExperienceBarWidget : public yap::ProgressBarWidget
  {
  public:
    PokemonExperienceBarWidget (bool inBattle);

    void Init ();

    void SetExperience (const yap::PokemonExperience& experience);

    void UpdateExperienceBar (yap::UInt16 levelEarned);

    virtual bool IsFocusable () const;

  protected:
    virtual void HandleUpdate (const yap::Time& dt);

  private:
    virtual void RefreshWidget ();

    const yap::PokemonExperience* experience_;
    bool inBattle_;
    yap::UInt16 levelEarned_;

    static const float MAX_BATTLE_EXP_BAR_SIZE;
    static const float MAX_TEAM_MANAGER_EXP_BAR_SIZE;

  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONEXPERIENCEBARWIDGET_HPP
