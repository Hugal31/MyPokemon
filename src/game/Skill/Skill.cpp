/*
** Skill.cpp for MyPokemon in /home/quief_h/rendu/MyPokemon/src/game/Skill
**
** Made by Hippolyte QUIEF
** Login   <quief_h@epitech.net>
**
** Started on  Fri Jun 12 14:51:40 2015 Hippolyte QUIEF
** Last update Fri Jun 12 18:48:19 2015 Hugo Laloge
*/

#include	<ostream>
#include	"game/Skill.hpp"

using namespace	game;

Skill::Skill() :
  _name("Unknown"),
  _id(0),
  _power(0),
  _precision(0),
  _pp(0),
  _skill_type(IS_PHYSIC)
{

}

/*
** Ageteurs
*/

const std::string	&Skill::get_name() const
{
  return (_name);
}

unsigned int	Skill::get_id() const
{
  return (_id);
}

Type	Skill::get_type() const
{
  return (_type);
}

unsigned int	Skill::get_power() const
{
  return (_power);
}

unsigned int	Skill::get_precision() const
{
  return (_precision);
}

unsigned int	Skill::get_pp() const
{
  return (_pp);
}

e_skill_type	Skill::get_skill_type() const
{
  return (_skill_type);
}

/*
** Asseteurs
*/

void		Skill::set_name(const std::string &name)
{
  _name = name;
}

void		Skill::set_skill_type(e_skill_type skill_type)
{
  _skill_type = skill_type;
}

std::ostream	&operator<<(std::ostream &os, const Skill &skill)
{
  (void)skill;
  return (os);
}
