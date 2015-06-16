/*
** StatModel.hpp for my_pokemon in /home/quief_h/rendu/MyPokemon/include/game
**
** Made by Hippolyte QUIEF
** Login   <quief_h@epitech.net>
**
** Started on  Fri May 29 15:36:28 2015 Hippolyte QUIEF
** Last update Tue Jun 16 15:22:03 2015 Hugo Laloge
*/

#ifndef		STATMODEL_HPP_
# define	STATMODEL_HPP_

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
  class			StatModel
  {
  protected:
    friend class	boost::serialization::access;
    unsigned short int	_stat_base;
    unsigned short int	_give_ev;

    /* Serialisation */
    template<class Archive>
    void	serialize(Archive &ar, const unsigned int version)
    {
      (void)version;
      ar & _stat_base;
      ar & _give_ev;
    }

  public:
    StatModel(const StatModel &stat);
    StatModel(unsigned short int stat_base = 0, unsigned short int give_ev = 0);
    virtual ~StatModel();

    virtual void	display(std::ostream &os = std::cout) const;

    /* Accesseurs */
    unsigned short int	get_stat_base() const;
    unsigned short int	get_give_ev() const;

    void	set_stat_base(unsigned short int stat_base);
    void	set_give_ev(unsigned short int give_ev);
  };

  std::ostream	&operator<<(std::ostream &os, const StatModel &stat);
}

NO_WARNINGS
BOOST_CLASS_VERSION(game::StatModel, 0)
WARNINGS

#endif		/* !STATMODEL_HPP_ */
