/*
** StatModele.hpp for my_pokemon in /home/quief_h/rendu/MyPokemon/include/game
**
** Made by Hippolyte QUIEF
** Login   <quief_h@epitech.net>
**
** Started on  Fri May 29 15:36:28 2015 Hippolyte QUIEF
** Last update Tue Jun  9 16:01:28 2015 Hugo Laloge
*/

#ifndef		STATMODELE_HPP_
# define	STATMODELE_HPP_

# include	<iostream>

# include	"no_warnings.hpp"

NO_WARNINGS

# include	<boost/archive/text_oarchive.hpp>
# include	<boost/archive/text_iarchive.hpp>

WARNINGS

# define	STAT_IV_MAX	31
# define	STAT_EV_MAX	252

namespace game
{
  class			StatModele
  {
  protected:
    friend class	boost::serialization::access;
    unsigned int	_stat_base;
    unsigned int	_give_ev;
    bool		_is_hp;

    /* Serialisation */
    template<class Archive>
    void	serialize(Archive &ar, const unsigned int version)
    {
      (void)version;
      ar & _stat_base;
      ar & _give_ev;
    }

  public:
    StatModele(bool is_hp = false);
    virtual ~StatModele();

    virtual void	display(std::ostream &os = std::cout) const;

    /* Accesseurs */
    unsigned int	get_stat_base() const;
    unsigned int        get_give_ev() const;
  };

  std::ostream	&operator<<(std::ostream &os, const StatModele &stat);
}

NO_WARNINGS
BOOST_CLASS_VERSION(game::StatModele, 0)
WARNINGS

#endif		/* !STATMODELE_HPP_ */
