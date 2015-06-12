/*
** Stat.cpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue May 26 16:05:11 2015 Hugo Laloge
** Last update Fri Jun 12 10:10:10 2015 Hugo Laloge
*/

#include	<cstdlib>
#include	<ostream>
#include	"game/Stat.hpp"

using namespace	game;

/*
** @brief	Constructeur par defaut
**		N'utiliser que pour avant une désérialisation
*/
Stat::Stat() :
  _ev(0), _iv(0)
{

}

/*
** @brief	A utiliser lors de la creation d'un nouveau pokemon
*/
Stat::Stat(const StatModel &model) :
  StatModel(model),
  _ev(0), _iv(rand() % 32)
{

}

Stat::~Stat()
{

}

unsigned int	Stat::get_value(unsigned int level) const
{
  return (((((_iv + (2 * _stat_base) + (_ev / 4) * level) / 100 + 5))));
}

void	Stat::display(std::ostream &os) const
{
  os << "Base :\t" << _stat_base << std::endl
     << "EV :\t" << _ev << std::endl
     << "IV :\t" << _iv << std::endl
     << "Value at level 100 : " << get_value(100) << std::endl;
}

/*
** @brief	Constructeur par defaut
**		N'utiliser que pour avant une désérialisation
*/
StatHp::StatHp()
{

}

StatHp::StatHp(const StatModel &model) :
  Stat(model)
{

}

StatHp::~StatHp()
{

}

unsigned int	StatHp::get_value(unsigned int level) const
{
  return (((_iv + (2 * _stat_base) + (_ev / 4) + 100) * level / 100) + 10);
}
