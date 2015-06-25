/*
** Skill.cpp
** Created by laloge_h on 18 juin 06:08 2015.
*/

#include	<ostream>
#include	"game/Pokemon.hpp"
#include	"game/PokemonModel.hpp"
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

Skill::~Skill()
{

}

/**
 * @TODO	Rajouter en parametre les stats du combat actuel
 */
int	Skill::use(Pokemon &user, Pokemon &target)
{
  (void)user;
  (void)target;
  int	ret;

  ret = -1;
  if (_pp > 0)
    {
      _pp--;
      ret = 0;
    }
  return (ret);
}

unsigned int	Skill::calc_dammage(const Pokemon &user,
				    const Pokemon &target)
{
  unsigned int	dmg;

  dmg = ((2 * user.get_level() + 10) / 250
	 * ((_skill_type == IS_PHYSIC)
	    ? (user.get_atk_value() / target.get_def_value())
	    : (user.get_spa_value() / target.get_spd_value()))
	 * _power + 2);
  // STAB
  if (_type == PokemonModel::pokedex[user.get_id()]->get_types()[0]
      or _type == PokemonModel::pokedex[user.get_id()]->get_types()[1])
    dmg *= 1.5;
  // Types
  dmg *= _type.get_strengh(PokemonModel::pokedex[user.get_id()]->get_types()[0])
    * _type.get_strengh(PokemonModel::pokedex[user.get_id()]->get_types()[1]);
  ///<TODO Critcal
  ///<TODO Other
  ///<TODO Random
  return (dmg);
}

/*
** Accesseurs
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
** A n'utiliser que pour de l'edition
*/

void		Skill::set_name(const std::string &name)
{
  _name = name;
}

void            Skill::set_id(unsigned int id)
{
  _id = id;
}

void            Skill::set_type(Type type)
{
  _type = type;
}

void            Skill::set_power(unsigned int power)
{
  _power = power;
}

void            Skill::set_precision(unsigned int precision)
{
  _precision = precision;
}

void            Skill::set_pp(unsigned int pp)
{
  _pp = pp;
}

void		Skill::set_skill_type(e_skill_type skill_type)
{
  _skill_type = skill_type;
}

std::ostream	&operator<<(std::ostream &os, const Skill &skill)
{
  os << "Name : " << skill.get_name() << std::endl
     << "Id : " << skill.get_id() << std::endl
     << "PP : " << skill.get_pp() << std::endl;
  return (os);
}
