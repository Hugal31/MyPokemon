/*
** Stat.hpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue May 26 16:05:21 2015 Hugo Laloge
** Last update Wed Jun 10 16:37:37 2015 Hugo Laloge
*/

#ifndef		STAT_HPP_
# define	STAT_HPP_

# include	<iostream>
# include	"StatModele.hpp"

# include	"no_warnings.hpp"

NO_WARNINGS

# include	<boost/archive/text_oarchive.hpp>
# include	<boost/archive/text_iarchive.hpp>

WARNINGS

namespace game
{
  class			Stat : public StatModele
  {
    friend class	boost::serialization::access;
    unsigned int	_ev;
    unsigned int	_iv;

    /* Serialisation */
    template<class Archive>
    void		serialize(Archive &ar, const unsigned int version)
    {
      (void)version;
      ar & _stat_base;
      ar & _give_ev;
      ar & _ev;
      ar & _iv;
    }

  public:
    Stat(bool is_hp = false);

    virtual void	display(std::ostream &os = std::cout) const;

    /* Accesseurs */
    unsigned int	get_value_other(unsigned int level) const;
    unsigned int	get_value_hp() const;
  };
}

NO_WARNINGS
BOOST_CLASS_VERSION(game::Stat, 0)
WARNINGS

#endif		/* !STAT_HPP_ */
