/*
** main.cpp for editor in /home/laloge_h/projets/Perso/C++/MyPokemon/editor
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Fri May 29 16:33:40 2015 Hugo Laloge
** Last update Sun Jun 14 09:48:09 2015 Hugo Laloge
*/

#include <QApplication>
#include "mainwindow.hpp"

int	main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  return a.exec();
}
