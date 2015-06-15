/*
** Type.hpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon/src/game
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Fri May 29 18:17:33 2015 Hugo Laloge
** Last update Mon Jun 15 01:29:41 2015 Hugo Laloge
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

    static std::string	names[];
    static float        strengh[TYPE_END][TYPE_END];

  public:
    Type();
    Type(e_type value);
    Type(const std::string &value);

    /* Accesseur */
    e_type	get_value() const;
    const std::string	&get_name() const;
    float       get_strengh(const Type &target) const;

    /* Assesseur*/
    void	set_value(e_type type);
    void	set_value(const std::string &type);

    /* Surcharges */
    bool	operator==(const Type &other);
  };

  std::ostream	&operator<<(std::ostream &os, const game::Type &type);
}

#endif		/* !TYPE_H_ */
