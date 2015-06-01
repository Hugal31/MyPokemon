/*
** PokemonModele.hpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue May 26 15:26:57 2015 Hugo Laloge
** Last update Mon Jun  1 15:53:37 2015 Hugo Laloge
*/

#ifndef		POKEMON_MODELE_HPP_
# define	POKEMON_MODELE_HPP_

# include	<iostream>
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

# include	"Type.hpp"
# include	"StatModele.hpp"

namespace game
{
  class			PokemonModele
  {
  private:
    friend class	boost::serialization::access;

    unsigned int	_id;
    std::string		_name;
    Type		_types[2];

    /* Stats */

    game::StatModele	_hp;
    game::StatModele	_atk;
    game::StatModele	_def;
    game::StatModele	_spa;
    game::StatModele	_spd;
    game::StatModele	_spe;

    /* Serialisation */

    template<class Archive>
    void		serialize(Archive &ar, const unsigned int version)
    {
      (void)version;
      ar & _id;
      ar & _name;
      ar & _types;
      ar & _hp;
      ar & _atk;
      ar & _def;
      ar & _spa;
      ar & _spd;
      ar & _spe;
    }

  public:

    /* Constructeur */
    PokemonModele(unsigned int id);

    /* Accesseurs */
    unsigned int	get_id() const;
    const std::string	&get_name() const;

    /* Assesseurs */
    void	        set_name(const std::string &name);
  };

  std::ostream	&operator<<(std::ostream &os, const PokemonModele &pokemon);
}

BOOST_CLASS_VERSION(game::PokemonModele, 0)

#endif		/* !POKEMON_MODELE_HPP_ */
