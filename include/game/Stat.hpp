/*
** Stat.hpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue May 26 16:05:21 2015 Hugo Laloge
** Last update Wed May 27 07:56:54 2015 Hugo Laloge
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
