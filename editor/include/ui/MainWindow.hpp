/*
** MainWindow.hpp for editor in /home/laloge_h/rendu/MyPokemon/editor/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Mon Jun 15 11:36:24 2015 Hugo Laloge
** Last update Mon Jun 15 14:30:48 2015 Hugo Laloge
*/

#ifndef		MAINWINDOW_H_
# define	MAINWINDOW_H_

# include	"no_warnings.hpp"

NO_WARNINGS
# include    <QtWidgets>
WARNINGS

namespace ui
{
    class   MainWindow : public QMainWindow
    {
      Q_OBJECT

    private:

    public slots:
      void	open_file();

    public:
        MainWindow();
        ~MainWindow();
    };
}

#endif		/* !MAINWINDOW_H_ */
