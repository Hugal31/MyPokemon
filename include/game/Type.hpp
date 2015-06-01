/*
** Type.hpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon/src/game
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Fri May 29 18:17:33 2015 Hugo Laloge
** Last update Mon Jun  1 15:49:13 2015 Hugo Laloge
*/

#ifndef		TYPE_H_
# define	TYPE_H_

# include	<string>

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

enum	e_type
  {
    TYPE_NONE,
    TYPE_NORMAL
  };

namespace	game
{
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

    /* Accesseur */
    e_type	get_value() const;

    /* Assesseur*/
    void	set_value(e_type type);

    static std::string	names;
  };

  std::ostream	&operator<<(std::ostream &os, const Type &type);
}

#endif		/* !TYPE_H_ */
