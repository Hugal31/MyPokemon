/*
** StatModel.cpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue May 26 16:05:11 2015 Hugo Laloge
** Last update Wed Jun 10 16:45:33 2015 Hugo Laloge
*/

#include	<ostream>
#include	"game/StatModel.hpp"

using namespace	game;

StatModel::StatModel(bool is_hp) :
  _is_hp(is_hp)
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

unsigned int	StatModel::get_stat_base() const
{
  return (_stat_base);
}

unsigned int	StatModel::get_give_ev() const
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
