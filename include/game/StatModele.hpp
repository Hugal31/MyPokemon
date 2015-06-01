/*
** StatModele.hpp for my_pokemon in /home/quief_h/rendu/MyPokemon/include/game
**
** Made by Hippolyte QUIEF
** Login   <quief_h@epitech.net>
**
** Started on  Fri May 29 15:36:28 2015 Hippolyte QUIEF
** Last update Mon Jun  1 15:20:00 2015 Hugo Laloge
*/

#ifndef		STATMODELE_HPP_
# define	STATMODELE_HPP_

# include	<iostream>

# define	STAT_IV_MAX	31
# define	STAT_EV_MAX	252

namespace game
{
  class			StatModele
  {
  protected:
    unsigned int	_stat_base;
    unsigned int	_give_ev;

  public:
    StatModele();
    virtual ~StatModele();

    virtual void	display(std::ostream &os = std::cout) const;

    /* Accesseurs */
    unsigned int	get_stat_base() const;
    unsigned int        get_give_ev() const;
  };

  std::ostream	&operator<<(std::ostream &os, const StatModele &stat);
}

#endif		/* !STATMODELE_HPP_ */
