/*
** Stat.cpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue May 26 16:05:11 2015 Hugo Laloge
** Last update Wed Jun 10 16:45:35 2015 Hugo Laloge
*/

#include	<ostream>
#include	"game/Stat.hpp"

using namespace	game;

Stat::Stat(bool is_hp) :
  StatModel(is_hp)
{

}

/*
** Accesseurs
**
** @TODO : Rajouter la nature
*/

unsigned int	Stat::get_value_other(unsigned int level) const
{
  return (((((_iv + (2 * _stat_base) + (_ev / 4) * level) / 100 + 5))));
}

unsigned int	Stat::get_value_hp() const
{
  return (((_iv + (2 * _stat_base) + (_ev / 4) + 100) / 100) + 10);
}

void	Stat::display(std::ostream &os) const
{
  os << "Base :\t" << _stat_base << std::endl
     << "EV :\t" << _ev << std::endl
     << "IV :\t" << _iv << std::endl;
}
