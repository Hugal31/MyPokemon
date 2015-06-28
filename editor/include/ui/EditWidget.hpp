/*
** EditWidget.hpp for editor in /home/laloge_h/rendu/MyPokemon/editor/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue Jun 16 12:18:33 2015 Hugo Laloge
** Last update Sun Jun 28 21:39:32 2015 Hugo Laloge
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

    virtual void	save() = 0;
    virtual void	open_file(const QString &filename) = 0;
  };
}

#endif		/* !EDITWIDGET_H_ */
