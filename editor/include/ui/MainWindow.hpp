/*
** MainWindow.hpp for editor in /home/laloge_h/rendu/MyPokemon/editor/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Mon Jun 15 11:36:24 2015 Hugo Laloge
** Last update Sat Jun 27 16:19:13 2015 Hugo Laloge
*/

#ifndef		MAINWINDOW_H_
# define	MAINWINDOW_H_

# include	"no_warnings.hpp"

NO_WARNINGS
# include    <QtWidgets>
WARNINGS

# include	"EditWidget.hpp"

namespace ui
{
    class   MainWindow : public QMainWindow
    {
      Q_OBJECT

    private:
      EditWidget	*currentEditor;

    public slots:
      void	new_pokemon();
      void	new_skill();
      void	open_file();
      void	save_file();

    public:
        MainWindow();
        ~MainWindow();
    };
}

#endif		/* !MAINWINDOW_H_ */
