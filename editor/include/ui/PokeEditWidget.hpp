/*
** PokeEditWidget.hpp for editor in /home/laloge_h/rendu/MyPokemon/editor/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Mon Jun 15 14:26:11 2015 Hugo Laloge
** Last update Sun Jun 28 21:39:54 2015 Hugo Laloge
*/

#ifndef		POKEEDITWIDGET_HPP_
# define	POKEEDITWIDGET_HPP_

# include	"no_warnings.hpp"
NO_WARNINGS
# include	<QtWidgets>
WARNINGS

namespace game
{
  class	PokemonModel;
}

#include	"EditWidget.hpp"
#include	"TypeWidget.hpp"
#include	"game/xp.hpp"

namespace
{

  class	XpWidget : public QComboBox
  {
  public:
    XpWidget(QWidget *parent = NULL) : QComboBox(parent)
    {
      addItem(tr("ERRATIC (600000)"));
      addItem(tr("FAST (800000)"));
      addItem(tr("MED_FAST (1000000)"));
      addItem(tr("MED_SLOW (1059860)"));
      addItem(tr("SLOW (1250000)"));
      addItem(tr("FLUCTUATING (1640000)"));
    }

    game::e_xp_type	get_value() const
    {
      game::e_xp_type	ret;

      switch(currentIndex())
	{
	case 0:
	  ret = game::XP_ERRATIC;
	  break;
	case 1:
	  ret = game::XP_FAST;
	  break;
	case 2:
	  ret = game::XP_MED_FAST;
	  break;
	case 3:
	  ret = game::XP_SLOW;
	  break;
	case 4:
	  ret = game::XP_FLUCTUATING;
	  break;
	}
      return (ret);
    }

    void	set_value(game::e_xp_type xp_type)
    {
      switch (xp_type)
	{
	default:
	case game::XP_ERRATIC:
	  setCurrentIndex(0);
	  break;
	case game::XP_FAST:
	  setCurrentIndex(1);
	  break;
	case game::XP_MED_FAST:
	  setCurrentIndex(2);
	  break;
	case game::XP_SLOW:
	  setCurrentIndex(3);
	  break;
	case game::XP_FLUCTUATING:
	  setCurrentIndex(4);
	  break;
	}
    }
  };
}

namespace	ui
{
  class	PokeEditWidget : public EditWidget
  {
    //Q_OBJECT
  private:
    /* Main info  */
    QSpinBox	*id;
    QLineEdit	*name;
    QLineEdit	*species;
    QPlainTextEdit	*resum;
    XpWidget	*xp;
    TypeWidget	*types[2];

    /* Secondary info */
    QDoubleSpinBox	*height;
    QDoubleSpinBox	*weight;
    QSpinBox		*catch_rate;
    QSpinBox		*gender_rate;

    /* Stats info */
    QSpinBox	*hp_base;
    QSpinBox	*hp_ev;
    QSpinBox	*atk_base;
    QSpinBox	*atk_ev;
    QSpinBox	*def_base;
    QSpinBox	*def_ev;
    QSpinBox	*spa_base;
    QSpinBox	*spa_ev;
    QSpinBox	*spd_base;
    QSpinBox	*spd_ev;
    QSpinBox	*spe_base;
    QSpinBox	*spe_ev;
    QSpinBox	*xp_base;

    void	init_layout(void);

  public slots:

  public:
    PokeEditWidget(const QString &filename,
		   QWidget *parent = 0, Qt::WindowFlags f = 0);
    PokeEditWidget(QWidget *parent = 0, Qt::WindowFlags f = 0);
    ~PokeEditWidget();

    void	save();
    void	open_file(const QString &filename);
    void	load_poke(const game::PokemonModel &poke);
    void        save_poke(game::PokemonModel &poke);

  };
}

#endif		/* !POKEEDITWIDGET_HPP_ */
