/*
** StatModel.cpp
** Created by laloge_h on 18 juin 06:09 2015.
*/

#include	<ostream>
#include	"game/StatModel.hpp"

using namespace	game;

StatModel::StatModel(const StatModel &stat) :
  _stat_base(stat._stat_base),
  _give_ev(stat._give_ev)
{

}

StatModel::StatModel(unsigned short int stat_base, unsigned short int give_ev) :
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
** Assesseurs
*/

void	StatModel::set_stat_base(unsigned short int stat_base)
{
  _stat_base = stat_base;
}

void	StatModel::set_give_ev(unsigned short int give_ev)
{
  _give_ev = give_ev;
}

/*
** Surcharges d'operateur externes
*/

std::ostream	&game::operator<<(std::ostream &os, const StatModel &stat)
{
  stat.display(os);
  return (os);
}
