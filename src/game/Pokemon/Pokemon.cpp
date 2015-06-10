/*
** Pokemon.cpp for MyPokemon in /home/quief_h/rendu/MyPokemon/src/game/Pokemon
**
** Made by Hippolyte QUIEF
** Login   <quief_h@epitech.net>
**
** Started on  Wed Jun 10 12:54:45 2015 Hippolyte QUIEF
** Last update Wed Jun 10 13:46:04 2015 Hippolyte QUIEF
*/

#include	<ostream>
#include	<string>
#include	"game/PokemonModele.hpp"
#include	"game/Pokemon.hpp"

using namespace	game;

Pokemon::Pokemon(const PokemonModele &model)
{

}

/*
** Ageteurs
*/

const std::string	&Pokemon::get_nickname() const
{
  return (_nickname);
}

unsigned int	Pokemon::get_id() const
{
  return (_id);
}

unsigned int	Pokemon::get_level() const
{
  return (_level);
}

e_catch		Pokemon::get_value() const
{
  return (_value);
}

unsigned int	Pokemon::get_xp() const
{
  return (_xp);
}

const Stat		&Pokemon::get_hp() const
{
  return (_hp);
}

const Stat		&Pokemon::get_atk() const
{
  return (_atk);
}

const Stat		&Pokemon::get_def() const
{
  return (_def);
}

const Stat		&Pokemon::get_spa() const
{
  return (_spa);
}

const Stat		&Pokemon::get_spd() const
{
  return (_spd);
}

const Stat		&Pokemon::get_spe() const
{
  return (_spe);
}

/*
** Asseteur
*/

void	Pokemon::set_nickname(const std::string &nickname)
{
  _nickname = nickname;
}

void	Pokemon::set_catch_value(e_catch value)
{
  _value = value;
}

/*
** Surcharge externes
*/

std::ostream	&game::operator<<(std::ostream &os, const Pokemon &pokemon)
{
  os << "Id : " << pokemon.get_id() << std::endl
     << "Nickname : " << pokemon.get_nickname() << std::endl
     << "Types : " << std::endl
     << "Level : " << pokemon.get_level() << std::endl
     << "Xp : " << pokemon.get_xp() << std::endl;
  /* Stats */
  return (os);
}
