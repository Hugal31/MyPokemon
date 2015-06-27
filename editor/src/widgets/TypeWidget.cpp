/*
** TypeWidget.cpp for editor in /home/laloge_h/rendu/MyPokemon/editor/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Sat Jun 27 14:13:01 2015 Hugo Laloge
** Last update Sat Jun 27 14:17:12 2015 Hugo Laloge
*/

#include	"game/Type.hpp"
#include	"TypeWidget.hpp"

using namespace	ui;

TypeWidget::TypeWidget(QWidget *parent) : QComboBox(parent)
{
  for (unsigned int i(game::TYPE_NONE); i < game::TYPE_END; i++)
    addItem(QString(game::Type::names[i].c_str()));
}
