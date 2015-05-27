/*
** Stat.cpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue May 26 16:05:11 2015 Hugo Laloge
** Last update Wed May 27 07:56:07 2015 Hugo Laloge
*/

#include	<ostream>
#include	"game/Stat.hpp"

using namespace	game;

Stat::Stat()
{
  (void)_value;
}

/*
** Surcharges d'operateur externes
*/

std::ostream	&game::operator<<(std::ostream &os, const Stat &stat)
{
  os << "Value : " << stat << std::endl;
  return (os);
}
