/*
** PokeEditWidget.hpp for editor in /home/laloge_h/rendu/MyPokemon/editor/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Mon Jun 15 14:26:11 2015 Hugo Laloge
** Last update Mon Jun 15 14:35:38 2015 Hugo Laloge
*/

#ifndef		POKEEDITWIDGET_H_
# define	POKEEDITWIDGET_H_

# include	"no_warnings.hpp"

NO_WARNINGS
# include    <QtWidgets>
WARNINGS

namespace	ui
{
  class	PokeEditWidget : public QWidget
  {
    Q_OBJECT

  private:

  public slots:

  public:
    PokeEditWidget(QWidget *parent = NULL);
    ~PokeEditWidget();
  };
}

#endif		/* !POKEEDITWIDGET_H_ */
