/*
** PokemonModele.cpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue May 26 15:26:27 2015 Hugo Laloge
** Last update Tue May 26 16:02:22 2015 Hugo Laloge
*/

#include	<iostream>
#include	<string>
#include	"game/PokemonModele.hpp"

using namespace	game;

PokemonModele::PokemonModele(unsigned int id) : _id(id)
{
  //Ouvrir le fichier/DB et parser les infos
}

/*
** Accesseurs
*/

unsigned int	PokemonModele::get_id() const
{
  return (_id);
}

const std::string	&PokemonModele::get_name() const
{
  return (_name);
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
