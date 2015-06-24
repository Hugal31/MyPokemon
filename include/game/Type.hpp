/*
** Type.hpp
** Created by laloge_h on 18 juin 06:03 2015.
*/

#ifndef		TYPE_H_
# define	TYPE_H_

# include	<string>

# include	"no_warnings.hpp"

NO_WARNINGS
# include	<boost/archive/text_oarchive.hpp>
# include	<boost/archive/text_iarchive.hpp>
WARNINGS

namespace	game
{
  enum	e_type
    {
      TYPE_NONE,
      TYPE_NORMAL,
      TYPE_FIGHT,
      TYPE_FLYINIG,
      TYPE_POISON,
      TYPE_GROUND,
      TYPE_ROCK,
      TYPE_BUG,
      TYPE_GHOST,
      TYPE_STEEL,
      TYPE_FIRE,
      TYPE_WATER,
      TYPE_GRASS,
      TYPE_ELECTRIC,
      TYPE_PSYCHIC,
      TYPE_ICE,
      TYPE_DRAGON,
      TYPE_DARK,
      TYPE_END
    };

  class		Type
  {
  private:
    friend class	boost::serialization::access;
    e_type	_value;

    /* Serialisation */
    template<class Archive>
    void		serialize(Archive &ar, const unsigned int version)
    {
      (void)version;
      ar & _value;
    }

    static float        strengh[TYPE_END][TYPE_END];

  public:
    Type();
    Type(e_type value);
    Type(const std::string &value);

    /* Accesseur */
    e_type	        get_value() const;
    const std::string	&get_name() const;
    float               get_strengh(const Type &target) const;

    /* Assesseur*/
    void	set_value(e_type type);
    void	set_value(const std::string &type);

    /* Surcharges */
    bool	operator==(const Type &other);

    static std::string	names[];
  };

  std::ostream	&operator<<(std::ostream &os, const game::Type &type);
}

#endif		/* !TYPE_H_ */
