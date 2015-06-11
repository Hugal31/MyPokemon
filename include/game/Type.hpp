/*
** Type.hpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon/src/game
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Fri May 29 18:17:33 2015 Hugo Laloge
** Last update Thu Jun 11 17:09:17 2015 Hugo Laloge
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

  public:
    Type();
    Type(e_type value);
    Type(const std::string &value);

    /* Accesseur */
    e_type	get_value() const;

    /* Assesseur*/
    void	set_value(e_type type);
    void	set_value(const std::string &type);

    static std::string	names[];
  };

  std::ostream	&operator<<(std::ostream &os, const Type &type);
}

#endif		/* !TYPE_H_ */
