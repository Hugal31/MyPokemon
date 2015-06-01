/*
** PokemonModele.cpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue May 26 15:26:27 2015 Hugo Laloge
** Last update Mon Jun  1 17:10:17 2015 Hugo Laloge
*/

#include	<ostream>
#include	<string>
#include	"game/PokemonModele.hpp"

using namespace	game;

PokemonModele::PokemonModele(unsigned int id) :
  _id(id), _max_xp(0), _heigth(10), _weight(10),
  _catch_rate(50), _gender_rate(50), _hp(true)
{
  //Ouvrir le fichier/DB et parser les infos
}

/*
** Accesseurs
*/

const std::string	&PokemonModele::get_name() const
{
  return (_name);
}

const std::string	&PokemonModele::get_species() const
{
  return (_species);
}

const std::string	&PokemonModele::get_resum() const
{
  return (_resum);
}

const Type	*PokemonModele::get_type()
{
  return (_types);
}

unsigned int	PokemonModele::get_id() const
{
  return (_id);
}

unsigned int	PokemonModele::get_max_xp() const
{
  return (_max_xp);
}

unsigned short int	PokemonModele::get_heigth() const
{
  return (_heigth);
}

unsigned short int	PokemonModele::get_weight() const
{
  return (_weight);
}

unsigned short int	PokemonModele::get_catch_rate() const
{
  return (_catch_rate);
}

unsigned short int	PokemonModele::get_gender_rate() const
{
  return (_gender_rate);
}

/*
** Asseteurs
*/

void	PokemonModele::set_name(const std::string &name)
{
  _name = name;
}

/*
** Surcharge externes
*/

std::ostream	&game::operator<<(std::ostream &os, const PokemonModele &pokemon)
{
  os << "Id : " << pokemon.get_id() << std::endl;
  os << "Name : " << pokemon.get_name() << std::endl;
  return (os);
}
