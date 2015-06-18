/*
** Type.cpp
** Created by laloge_h on 18 juin 06:10 2015.
*/

#include	<string>
#include	<ostream>
#include	"game/Type.hpp"

using namespace	game;

float	Type::strengh[TYPE_END][TYPE_END] =
  {
    //   ,NOR, FIG, FLY, PSN, GRO, ROC, BUG, GHO, STE, FIR, WAT, GRA, ELE, PSY, ICE, DRA, DAR
    {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0},  //NONE
    {1.0, 1.0, 1.0, 0.5, 0.5, 1.0, 0.5, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0},  //NORMAL
    {1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 0.0, 2.0, 1.0, 1.0, 1.0, 1.0, 0.5, 2.0, 1.0, 2.0},  //FIGHT
    {1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 0.5, 2.0, 1.0, 0.5, 1.0, 1.0, 2.0, 0.5, 1.0, 1.0, 1.0, 1.0},  //FLYING
    {1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 0.5, 1.0, 0.5, 0.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0},  //POISON
    {1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 2.0, 0.5, 1.0, 2.0, 2.0, 1.0, 0.5, 2.0, 1.0, 1.0, 1.0, 1.0},  //GROUND
    {1.0, 1.0, 0.5, 2.0, 0.5, 0.5, 1.0, 2.0, 1.0, 0.5, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0},  //ROCK
    {1.0, 1.0, 0.5, 0.5, 1.0, 1.0, 1.0, 1.0, 0.5, 0.5, 0.5, 1.0, 2.0, 1.0, 2.0, 1.0, 1.0, 2.0},  //BUG
    {1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 2.0, 0.5, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 0.5},  //GHOST
    {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 0.5, 0.5, 0.5, 1.0, 0.5, 1.0, 2.0, 1.0, 1.0},  //STEEL
    {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 1.0, 2.0, 0.5, 0.5, 2.0, 1.0, 1.0, 2.0, 0.5, 1.0},  //FIRE
    {1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 1.0, 2.0, 0.5, 0.5, 1.0, 1.0, 1.0, 0.5, 1.0},  //WATER
    {1.0, 1.0, 1.0, 0.5, 0.5, 2.0, 1.0, 0.5, 1.0, 0.5, 0.5, 2.0, 0.5, 1.0, 1.0, 1.0, 0.5, 1.0},  //GRASS
    {1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 0.5, 1.0, 1.0, 0.5, 1.0},  //ELECTRIC
    {1.0, 1.0, 2.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 0.0},  //PSYCHIC
    {1.0, 1.0, 1.0, 2.0, 1.0, 2.0, 1.0, 1.0, 1.0, 0.5, 0.5, 0.5, 2.0, 1.0, 1.0, 0.5, 2.0, 1.0},  //ICE
    {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0},  //DRAGON
    {1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 0.5}   //DARK
  };

std::string	Type::names[] = {"NONE", "NORMAL", "FIGHT", "FLYING", "POISON", "GROUND", "ROCK", "BUG", "GHOST",
                                "STEEL", "FIRE", "WATER", "GRASS", "ELECTRIC", "PSYCHIC", "ICE", "DRAGON", "DARK"};

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
