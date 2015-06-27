/*
** SkillEditWidget.hpp for editor in /home/laloge_h/rendu/MyPokemon/editor/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Sat Jun 27 14:05:48 2015 Hugo Laloge
** Last update Sat Jun 27 16:16:46 2015 Hugo Laloge
*/

#ifndef		SKILLEDITWIDGET_HPP_
# define	SKILLEDITWIDGET_HPP_

# include	"no_warnings.hpp"
NO_WARNINGS
# include	<QtWidgets>
WARNINGS

# include	"EditWidget.hpp"
# include	"TypeWidget.hpp"
# include	"game/Skill.hpp"

namespace	ui
{
  class	SkillEditWidget : public EditWidget
  {
    //Q_OBJECT
  private:
    QSpinBox	*id;
    QLineEdit	*name;
    TypeWidget	*type;
    QSpinBox	*power;
    QSpinBox	*precision;
    QSpinBox	*pp;
    QComboBox	*skill_type;

    void	init_layout();

  public:
    SkillEditWidget(QWidget *parent = 0, Qt::WindowFlags f = 0);
    SkillEditWidget(const QString &filename,
				     QWidget *parent = 0, Qt::WindowFlags f = 0);
    ~SkillEditWidget();
    void	open_skill(const QString &filename);
    void	load_skill(const game::Skill &skill);
    void	save();
  };
}

#endif	       /* !SKILLEDITWIDGET_HPP_ */
