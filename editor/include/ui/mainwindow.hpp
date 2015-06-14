/*
** mainwindow.hpp for editor in /home/laloge_h/rendu/MyPokemon/editor/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Sun Jun 14 09:59:48 2015 Hugo Laloge
** Last update Sun Jun 14 10:01:01 2015 Hugo Laloge
*/

#ifndef MAINWINDOW_HPP_
#define MAINWINDOW_HPP_

# include <QMainWindow>

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

  void	on_actionQuit_clicked();

private:
  Ui::MainWindow *ui;
};

#endif /* !MAINWINDOW_HPP_ */
