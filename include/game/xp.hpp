/*
** xp.hpp for MyPokemon in /home/quief_h/rendu/MyPokemon/include/game
**
** Made by Hippolyte QUIEF
** Login   <quief_h@epitech.net>
**
** Started on  Tue Jun  9 14:08:20 2015 Hippolyte QUIEF
** Last update Tue Jun  9 16:39:14 2015 Hippolyte QUIEF
*/

#ifndef		XP_HPP_
# define	XP_HPP_

# include	<string>

namespace	game
{
  enum	e_xp_type
    {
      XP_ERRATIC,
      XP_FAST,
      XP_MED_FAST,
      XP_MED_SLOW,
      XP_SLOW,
      XP_FLUCTUATING
    };
}

unsigned int		xp_from_level(unsigned int current_lv, unsigned int xp_max);
unsigned int	    nb_level_pass(unsigned int level, unsigned int current_xp,
			                  unsigned int xp_gain, unsigned xp_max);



#endif		/* !XP_HPP_ */
