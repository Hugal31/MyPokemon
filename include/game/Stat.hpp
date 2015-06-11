/*
** Stat.hpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue May 26 16:05:21 2015 Hugo Laloge
** Last update Thu Jun 11 14:06:41 2015 Hugo Laloge
*/

#ifndef		STAT_HPP_
# define	STAT_HPP_

# include	<iostream>
# include	"StatModel.hpp"

# include	"no_warnings.hpp"

NO_WARNINGS
# include	<boost/archive/text_oarchive.hpp>
# include	<boost/archive/text_iarchive.hpp>
WARNINGS

namespace game
{
  class			Stat : public StatModel
  {
  protected:
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
    Stat();
    Stat(const StatModel &model);
    virtual	~Stat();

    void	display(std::ostream &os = std::cout) const;
    virtual unsigned int	get_value(unsigned int level) const;
  };

  class		StatHp : public Stat
  {
  public:
    StatHp();
    StatHp(const StatModel &model);
    virtual	~StatHp();

    unsigned int	get_value(unsigned int level) const;
  };
}

NO_WARNINGS
BOOST_CLASS_VERSION(game::Stat, 0)
WARNINGS

#endif		/* !STAT_HPP_ */
