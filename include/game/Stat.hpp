/*
** Stat.hpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue May 26 16:05:21 2015 Hugo Laloge
** Last update Mon Jun  1 16:20:27 2015 Hugo Laloge
*/

#ifndef		STAT_HPP_
# define	STAT_HPP_

# include	<iostream>
# include	"StatModele.hpp"

# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wweak-vtables"
# pragma clang diagnostic ignored "-Wextra-semi"
# pragma clang diagnostic ignored "-Wconversion"
# pragma clang diagnostic ignored "-Wunused-parameter"
# pragma clang diagnostic ignored "-Wundef"
# pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
# pragma clang diagnostic ignored "-Wdeprecated"
# pragma clang diagnostic ignored "-Wglobal-constructors"
# pragma clang diagnostic ignored "-Wexit-time-destructors"
# pragma clang diagnostic ignored "-Wdivision-by-zero"

# include	<boost/archive/text_oarchive.hpp>
# include	<boost/archive/text_iarchive.hpp>

# pragma clang diagnostic pop

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
    Stat(bool is_hp);

    virtual void	display(std::ostream &os = std::cout) const;

    /* Accesseurs */
    unsigned int	get_value_other(unsigned int level) const;
    unsigned int	get_value_hp() const;
  };
}

BOOST_CLASS_VERSION(game::Stat, 0)

#endif		/* !STAT_HPP_ */
