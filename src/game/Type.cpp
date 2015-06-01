/*
** Type.cpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon/src/game
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Fri May 29 18:25:30 2015 Hugo Laloge
** Last update Fri May 29 18:46:32 2015 Hugo Laloge
*/

#include	<string>
#include	<ostream>
#include	"game/Type.hpp"

using namespace	game;

std::string	Type::names("NORMAL");

Type::Type(e_type value):
  _value(value)
{

}

e_type	Type::get_value() const
{
  return (_value);
}

std::ostream	&game::operator<<(std::ostream &os, const Type &type)
{
  os << game::Type::names[type.get_value()];
  return (os);
}
