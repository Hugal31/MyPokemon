/*
** Stat.cpp
** Created by laloge_h on 18 juin 06:08 2015.
*/

#include	<cstdlib>
#include	<ostream>
#include	"game/Stat.hpp"

using namespace	game;

/**
 * @brief	Constructeur par defaut
 *		N'utiliser que pour avant une désérialisation
 */
Stat::Stat() :
  _ev(0), _iv(0)
{

}

/**
 * @brief	A utiliser lors de la creation d'un nouveau pokemon
 */
Stat::Stat(const StatModel &model) :
  StatModel(model),
  _ev(0), _iv(rand() % 32)
{

}

Stat::~Stat()
{

}

unsigned int	Stat::calc_value(unsigned int level) const
{
  return ((_iv + (2 * _stat_base) + (_ev / 4) * level) / 100 + 5);
}

void	Stat::init_value(unsigned int level)
{
  _value = calc_value(level);
}

unsigned int	Stat::get_value() const
{
  return (_value);
}

void	Stat::display(std::ostream &os) const
{
  os << "Base :\t" << _stat_base << std::endl
     << "EV :\t" << _ev << std::endl
     << "IV :\t" << _iv << std::endl
     << "Value at level 100 : " << calc_value(100) << std::endl;
}

/**
 * @brief	Constructeur par defaut
 *		N'utiliser que pour avant une désérialisation
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

unsigned int	StatHp::calc_value(unsigned int level) const
{
  return ((_iv + (2 * _stat_base) + (_ev / 4) + 100) * level / 100 + 10);
}
