/*
** Stat.hpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue May 26 16:05:21 2015 Hugo Laloge
** Last update Mon Jun  1 15:26:44 2015 Hugo Laloge
*/

#ifndef		STAT_HPP_
# define	STAT_HPP_

# include	<iostream>
# include	"StatModele.hpp"

namespace game
{
  class			Stat : public StatModele
  {
    unsigned int	_ev;
    unsigned int	_iv;

  public:
    Stat();

    virtual void	display(std::ostream &os = std::cout) const;

    /* Accesseurs */
    unsigned int	get_value_other(unsigned int level) const;
    unsigned int	get_value_hp() const;
  };
}

#endif		/* !STAT_HPP_ */
