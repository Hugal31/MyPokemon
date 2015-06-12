/*
** Skill.cpp for MyPokemon in /home/quief_h/rendu/MyPokemon/src/game/Skill
**
** Made by Hippolyte QUIEF
** Login   <quief_h@epitech.net>
**
** Started on  Fri Jun 12 14:51:40 2015 Hippolyte QUIEF
** Last update Fri Jun 12 15:35:14 2015 Hippolyte QUIEF
*/

#include	<ostream>
#include	<string>
#include	"game/Skill.hpp"
#include	"game/Type.hpp"

using namespace	game;

/*
** Ageteurs
*/

const std::string	&Skill::get_name() const
{
  return (_name);
}

unsigned int		&Skill::get_id() const
{
  return (_id);
}

const Type		&Skill::get_types() const
{
  return (_types);
}

unsigned int		&Skill::get_power() const
{
  return (_power);
}

unsigned int		&Skill::get_precision() const
{
  return (_precision);
}

unsigned int		&Skill::get_pp() const
{
  return (_pp);
}

e_type_move		&Skill::get_type_skill() const
{
  return (_type_skill);
}

/*
** Asseteurs
*/

void		Skill::set_name(const std::string &name)
{
  _name = name;
}

void		Skill::set_type_skill(e_type_move type_skill)
{
  _type_skill = type_skill;
}

std::ostream	&operator<<(std::ostream &os)
{
  ;
}
