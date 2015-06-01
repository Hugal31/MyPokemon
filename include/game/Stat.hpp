/*
** Stat.hpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue May 26 16:05:21 2015 Hugo Laloge
// Last update Fri May 29 15:36:10 2015 Hippolyte QUIEF
*/

#ifndef		STAT_HPP_
# define	STAT_HPP_

# include	<ostream>

namespace game
{
  class			Stat
  {
    unsigned int	_value;

  public:
    Stat();
  };
  std::ostream	&operator<<(std::ostream &os, const Stat &stat);
}

#endif		/* !STAT_HPP_ */
