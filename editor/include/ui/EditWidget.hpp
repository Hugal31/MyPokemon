/*
** EditWidget.hpp for editor in /home/laloge_h/rendu/MyPokemon/editor/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue Jun 16 12:18:33 2015 Hugo Laloge
** Last update Tue Jun 16 13:28:24 2015 Hugo Laloge
*/

#ifndef		EDITWIDGET_H_
# define	EDITWIDGET_H_

# include	"no_warnings.hpp"
NO_WARNINGS
# include	<QtWidgets>
WARNINGS

namespace ui
{
  class	EditWidget : public QWidget
  {
    Q_OBJECT
  protected:

  public slots:

  public:
    EditWidget(QWidget *parent = 0, Qt::WindowFlags f = 0);
    ~EditWidget();

    virtual void	save(const QString &path = ".") = 0;
  };
}

#endif		/* !EDITWIDGET_H_ */
