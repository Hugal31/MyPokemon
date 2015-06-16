/*
** main.cpp for editor in /home/laloge_h/projets/Perso/C++/MyPokemon/editor
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Fri May 29 16:33:40 2015 Hugo Laloge
** Last update Tue Jun 16 11:56:44 2015 Hugo Laloge
*/

#include <QApplication>
#include "MainWindow.hpp"

int	main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  QString locale = QLocale::system().name().section('_', 0, 0);
  QTranslator translator;
  translator.load(QString("translations/editor_") + locale);
  a.installTranslator(&translator);

  ui::MainWindow w;
  w.show();

  return a.exec();
}
