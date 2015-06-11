/*
** Type.cpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon/src/game
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Fri May 29 18:25:30 2015 Hugo Laloge
** Last update Thu Jun 11 18:23:03 2015 Hugo Laloge
*/

#include	<string>
#include	<ostream>
#include	"game/Type.hpp"

using namespace	game;

std::string	Type::names[] = {"NONE", "NORMAL", "FIGHT"};

Type::Type() :
  _value(TYPE_NONE)
{

}

Type::Type(e_type value):
  _value(value)
{

}

Type::Type(const std::string &value)
{
  set_value(value);
}

e_type	Type::get_value() const
{
  return (_value);
}

void	Type::set_value(e_type type)
{
  _value = type;
}

void	Type::set_value(const std::string &type)
{
  unsigned int i(TYPE_NONE);

  for (; i < TYPE_END && names[i] != type; i++);
  if (i != TYPE_END)
    _value = static_cast<e_type>(i);
  else
    std::cerr << "Unknowned type : " << type << std::endl;
}

std::ostream	&game::operator<<(std::ostream &os, const Type &type)
{
  os << game::Type::names[type.get_value()];
  return (os);
}
