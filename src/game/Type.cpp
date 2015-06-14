/*
** Type.cpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon/src/game
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Fri May 29 18:25:30 2015 Hugo Laloge
** Last update Mon Jun 15 01:30:26 2015 Hugo Laloge
*/

#include	<string>
#include	<ostream>
#include	"game/Type.hpp"

using namespace	game;

float	Type::strengh[TYPE_END][TYPE_END] =
  {
    //   ,NML, FGHT
    {1.0, 1.0, 1.0},	//NONE
    {1.0, 1.0, 1.0},	//NORMAL
    {1.0, 1.0, 1.0},	//FIGHT
  };

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

const std::string	&Type::get_name() const
{
  return (Type::names[_value]);
}

void	Type::set_value(e_type type)
{
  _value = type;
}

void		Type::set_value(const std::string &type)
{
  unsigned int	i;

  for (i = TYPE_NONE; i < TYPE_END && names[i] != type; i++);
  if (i != TYPE_END)
    _value = static_cast<e_type>(i);
  else
    std::cerr << "Unknowned type : " << type << std::endl;
}

float	Type::get_strengh(const Type &target) const
{
  return (strengh[_value][target.get_value()]);
}

bool	Type::operator==(const Type &other)
{
  return (_value == other.get_value());
}

std::ostream	&game::operator<<(std::ostream &os, const Type &type)
{
  os << type.get_name();
  return (os);
}
