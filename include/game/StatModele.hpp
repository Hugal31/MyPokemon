//
// StatModele.hpp for my_pokemon in /home/quief_h/rendu/MyPokemon/include/game
//
// Made by Hippolyte QUIEF
// Login   <quief_h@epitech.net>
//
// Started on  Fri May 29 15:36:28 2015 Hippolyte QUIEF
// Last update Fri May 29 16:06:23 2015 Hippolyte QUIEF
//

#ifndef		STATMODELE_HPP_
# define	STATMODELE_HPP_

/* stat_max -> iv_max(31) et ev_max(252) */

namespace game
{
  class			StatModele
  {
  private:
    unsigned int	_stat_base;
    unsigned int	_give_ev;
    unsigned int	_save_ev;
    unsigned int	_iv;

  public:
  };
}

#endif		/* !STATMODELE_HPP_ */
