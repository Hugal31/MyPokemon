/*
** PokeEditWidget.hpp for editor in /home/laloge_h/rendu/MyPokemon/editor/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Mon Jun 15 14:26:11 2015 Hugo Laloge
** Last update Mon Jun 15 17:04:33 2015 Hugo Laloge
*/

#ifndef		POKEEDITWIDGET_H_
# define	POKEEDITWIDGET_H_

# include	"no_warnings.hpp"
NO_WARNINGS
# include    <QtWidgets>
WARNINGS

#include	"game/Type.hpp"

namespace
{
  class	TypeWidget : public QComboBox
  {
  public:
    TypeWidget(QWidget *parent = NULL) : QComboBox(parent)
      {
	for (unsigned int i(game::TYPE_NONE); i < game::TYPE_END; i++)
	  addItem(QString(game::Type::names[i].c_str()));
      }
  };

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
  };
}

namespace	ui
{
  class	PokeEditWidget : public QWidget
  {
    Q_OBJECT

  private:
    /* Main info  */
    QSpinBox *id;
    QLineEdit *name;
    QLineEdit *species;
    QTextEdit *resum;
    XpWidget *xp;
    QLabel *type_label;
    TypeWidget *types[2];

    /* Secondary info */
    QDoubleSpinBox *heigth;
    QDoubleSpinBox *weight;
    QSpinBox *catch_rate;
    QSpinBox *gender_rate;

    /* Stats info */
    QSpinBox *hp_base;
    QSpinBox *hp_ev;
    QSpinBox *atk_base;
    QSpinBox *atk_ev;
    QSpinBox *def_base;
    QSpinBox *def_ev;
    QSpinBox *spa_base;
    QSpinBox *spa_ev;
    QSpinBox *spd_base;
    QSpinBox *spd_ev;
    QSpinBox *spe_base;
    QSpinBox *spe_ev;

  public slots:

  public:
    PokeEditWidget(QWidget *parent = NULL);
    ~PokeEditWidget();
  };
}

#endif		/* !POKEEDITWIDGET_H_ */
