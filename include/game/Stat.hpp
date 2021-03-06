/*
** Stat.hpp
** Created by laloge_h on 18 juin 06:01 2015.
*/

#ifndef         STAT_HPP_
# define        STAT_HPP_

# include	<iostream>
# include	"game/StatModel.hpp"

# include	"no_warnings.hpp"

NO_WARNINGS
# include	<boost/archive/text_oarchive.hpp>
# include	<boost/archive/text_iarchive.hpp>

WARNINGS

namespace game
{
  class Stat : public StatModel
  {
  protected:
    friend class boost::serialization::access;

    unsigned int _ev;
    unsigned int _iv;
    unsigned int _value;

    /* Serialisation */
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
      (void) version;
      ar &_stat_base;
      ar &_give_ev;
      ar &_ev;
      ar &_iv;
    }

    virtual unsigned int calc_value(unsigned int level) const;

  public:
    Stat();

    Stat(const StatModel &model);

    virtual        ~Stat();

    void display(std::ostream &os = std::cout) const;

    ///<brief	A utiliser avant un combat
    void init_value(unsigned int level);

    unsigned int get_value() const;

    unsigned int	operator=(unsigned int value);
    unsigned int	operator+=(unsigned int value);
    unsigned int	operator-=(unsigned int value);
  };

  class StatHp : public Stat
  {
    virtual unsigned int calc_value(unsigned int level) const;

  public:
    StatHp();

    StatHp(const StatModel &model);

    virtual        ~StatHp();
  };
}

NO_WARNINGS
BOOST_CLASS_VERSION(game::Stat, 0)
WARNINGS

#endif		/* !STAT_HPP_ */
