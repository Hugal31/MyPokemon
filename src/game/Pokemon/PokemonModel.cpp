/*
** PokemonModel.cpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue May 26 15:26:27 2015 Hugo Laloge
** Last update Thu Jun 11 18:40:19 2015 Hugo Laloge
*/

#include	<ostream>
#include	<string>
#include	"game/PokemonModel.hpp"

using namespace	game;

PokemonModel::PokemonModel(unsigned int id) :
  _id(id), _max_xp(0), _heigth(10), _weight(10),
  _catch_rate(50), _gender_rate(50), _hp(true)
{
  //Ouvrir le fichier/DB et parser les infos
}

/*
** Accesseurs
*/

const std::string	&PokemonModel::get_name() const
{
  return (_name);
}

const std::string	&PokemonModel::get_species() const
{
  return (_species);
}

const std::string	&PokemonModel::get_resum() const
{
  return (_resum);
}

const Type	*PokemonModel::get_types() const
{
  return (_types);
}

unsigned int	PokemonModel::get_id() const
{
  return (_id);
}

unsigned int	PokemonModel::get_max_xp() const
{
  return (_max_xp);
}

unsigned short int	PokemonModel::get_heigth() const
{
  return (_heigth);
}

unsigned short int	PokemonModel::get_weight() const
{
  return (_weight);
}

unsigned short int	PokemonModel::get_catch_rate() const
{
  return (_catch_rate);
}

unsigned short int	PokemonModel::get_gender_rate() const
{
  return (_gender_rate);
}

const StatModel	&PokemonModel::get_hp() const
{
  return (_hp);
}

const StatModel	&PokemonModel::get_atk() const
{
  return (_atk);
}

const StatModel	&PokemonModel::get_def() const
{
  return (_def);
}

const StatModel	&PokemonModel::get_spa() const
{
  return (_spa);
}

const StatModel	&PokemonModel::get_spd() const
{
  return (_spd);
}

const StatModel	&PokemonModel::get_spe() const
{
  return (_spe);
}

/*
** Asseteurs
*/

void	PokemonModel::set_name(const std::string &name)
{
  _name = name;
}

void	PokemonModel::set_species(const std::string &species)
{
  _species = species;
}

void	PokemonModel::set_resum(const std::string &resum)
{
  _resum = resum;
}

void	PokemonModel::set_types(const Type &type1, const Type &type2)
{
  _types[0] = type1;
  _types[1] = type2;
}

void	PokemonModel::set_types(const std::string &type1,
				const std::string &type2)
{
  _types[0].set_value(type1);
  _types[1].set_value(type2);
}

void	PokemonModel::set_max_xp(const unsigned int max_xp)
{
  _max_xp = max_xp;
}

void	PokemonModel::set_heigth(const unsigned short int heigth)
{
  _heigth = heigth;
}

void	PokemonModel::set_weight(const unsigned short int weight)
{
  _weight = weight;
}

void	PokemonModel::set_catch_rate(const unsigned short int catch_rate)
{
  _catch_rate = catch_rate;
}

void	PokemonModel::set_gender_rate(const unsigned short int gender_rate)
{
  _gender_rate = gender_rate;
}

/*
** Surcharge externes
*/

std::ostream	&game::operator<<(std::ostream &os, const PokemonModel &pokemon)
{
  os << "Id : " << pokemon.get_id() << std::endl
     << "Name : " << pokemon.get_name() << std::endl
     << "Resum : " << pokemon.get_resum() << std::endl
     << "Species : " << pokemon.get_species() << std::endl
     << "Types : " << pokemon.get_types()[0] << " and "
     << pokemon.get_types()[1] << std::endl
     << "Max xp : " << pokemon.get_max_xp() << std::endl
     << "Heigth : " << pokemon.get_heigth() << std::endl
     << "Weight : " << pokemon.get_weight() << std::endl
     << "Catch rate : " << pokemon.get_catch_rate() << std::endl
     << "Gender rate : " << pokemon.get_gender_rate() << std::endl;
  return (os);
}
