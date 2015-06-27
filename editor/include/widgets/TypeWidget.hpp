/*
** TypeWidget.hpp for editor in /home/laloge_h/rendu/MyPokemon/editor/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Sat Jun 27 14:13:47 2015 Hugo Laloge
** Last update Sat Jun 27 14:16:29 2015 Hugo Laloge
*/

#ifndef		TYPEWIDGET_HPP_
# define	TYPEWIDGET_HPP_

# include	"no_warnings.hpp"
NO_WARNINGS
# include	<QtWidgets>
WARNINGS

namespace	ui
{
  class	TypeWidget : public QComboBox
  {
  public:
    TypeWidget(QWidget *parent = NULL);
  };
}


#endif		/* !TYPEWIDGET_HPP_ */
