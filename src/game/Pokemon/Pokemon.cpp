/*
** Pokemon.cpp
** Created by laloge_h on 18 juin 06:08 2015.
*/

#include	<ostream>
#include	"game/Skill.hpp"
#include	"game/PokemonModel.hpp"
#include	"game/Pokemon.hpp"

using namespace        game;

Pokemon::Pokemon() :
  _nickname("Unknowned"),
  _id(0),
  _level(0),
  _owner(IS_WILD),
  _xp(0)
{

}

Pokemon::Pokemon(const PokemonModel &model, unsigned int level, e_owner owner) :
  _nickname(model.get_name()),
  _id(model.get_id()),
  _level(level),
  _owner(owner),
  /* _xp(xp_from_level()), */
  _hp(model.get_hp()),
  _atk(model.get_atk()),
  _def(model.get_def()),
  _spa(model.get_spa()),
  _spd(model.get_spd()),
  _spe(model.get_spe())
{

}

Pokemon::~Pokemon()
{

}

/*
** Accesseurs
*/

const std::string &Pokemon::get_nickname() const
{
  return (_nickname);
}

unsigned int        Pokemon::get_id() const
{
  return (_id);
}

unsigned int        Pokemon::get_level() const
{
  return (_level);
}

e_owner                Pokemon::get_owner() const
{
  return (_owner);
}

unsigned int        Pokemon::get_xp() const
{
  return (_xp);
}

const Stat &Pokemon::get_hp() const
{
  return (_hp);
}

const Stat &Pokemon::get_atk() const
{
  return (_atk);
}

const Stat &Pokemon::get_def() const
{
  return (_def);
}

const Stat &Pokemon::get_spa() const
{
  return (_spa);
}

const Stat &Pokemon::get_spd() const
{
  return (_spd);
}

const Stat &Pokemon::get_spe() const
{
  return (_spe);
}

unsigned int        Pokemon::get_atk_value() const
{
  return (_atk.get_value());
}

unsigned int        Pokemon::get_def_value() const
{
  return (_def.get_value());
}

unsigned int        Pokemon::get_spa_value() const
{
  return (_spa.get_value());
}

unsigned int        Pokemon::get_spd_value() const
{
  return (_spd.get_value());
}

unsigned int        Pokemon::get_spe_value() const
{
  return (_spe.get_value());
}

const Skill *Pokemon::get_skills() const
{
  return (_skills);
}

/*
** Asseteur
*/

void        Pokemon::set_nickname(const std::string &nickname)
{
  _nickname = nickname;
}

void        Pokemon::set_owner(e_owner owner)
{
  _owner = owner;
}

/*
** Surcharges externes
*/

std::ostream &operator<<(std::ostream &os, const Pokemon &pokemon)
{
  os << "Id : " << pokemon.get_id() << std::endl
  << "Nickname : " << pokemon.get_nickname() << std::endl
  << "Types : " << std::endl
  << "Level : " << pokemon.get_level() << std::endl
  << "Xp : " << pokemon.get_xp() << std::endl;
  /* Stats ? */
  return (os);
}
