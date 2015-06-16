/*
** StatModel.cpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue May 26 16:05:11 2015 Hugo Laloge
** Last update Tue Jun 16 14:33:17 2015 Hugo Laloge
*/

#include	<ostream>
#include	"game/StatModel.hpp"

using namespace	game;

StatModel::StatModel(const StatModel &stat) :
  _stat_base(stat._stat_base),
  _give_ev(stat._give_ev)
{

}

StatModel::StatModel(unsigned int stat_base, unsigned int give_ev) :
  _stat_base(stat_base),
  _give_ev(give_ev)
{

}

StatModel::~StatModel()
{

}

void	StatModel::display(std::ostream &os) const
{
  os << "Base : " << _stat_base << std::endl
     << "Gived ev : " << _give_ev << std::endl;
}

/*
** Accesseurs
*/

unsigned short int	StatModel::get_stat_base() const
{
  return (_stat_base);
}

unsigned short int	StatModel::get_give_ev() const
{
  return (_give_ev);
}

/*
** Surcharges d'operateur externes
*/

std::ostream	&game::operator<<(std::ostream &os, const StatModel &stat)
{
  stat.display(os);
  return (os);
}
