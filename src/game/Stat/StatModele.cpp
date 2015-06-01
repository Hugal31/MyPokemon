/*
** StatModele.cpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue May 26 16:05:11 2015 Hugo Laloge
** Last update Mon Jun  1 15:19:25 2015 Hugo Laloge
*/

#include	<ostream>
#include	"game/StatModele.hpp"

using namespace	game;

StatModele::StatModele()
{

}

StatModele::~StatModele()
{

}

void	StatModele::display(std::ostream &os) const
{
  os << "Base : " << _stat_base << std::endl
     << "Gived ev : " << _give_ev << std::endl;
}

/*
** Accesseurs
*/

unsigned int	StatModele::get_stat_base() const
{
  return (_stat_base);
}

unsigned int	StatModele::get_give_ev() const
{
  return (_give_ev);
}

/*
** Surcharges d'operateur externes
*/

std::ostream	&game::operator<<(std::ostream &os, const StatModele &stat)
{
  stat.display(os);
  return (os);
}
