/*
** PokemonModele.hpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue May 26 15:26:57 2015 Hugo Laloge
** Last update Wed May 27 21:11:00 2015 Hugo Laloge
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

# include	<boost/archive/text_oarchive.hpp>
# include	<boost/archive/text_iarchive.hpp>

# pragma clang diagnostic pop

# include	"Stat.hpp"


namespace game
{
  class			PokemonModele
  {
    const unsigned int	_id;
    std::string		_name;

    /* Stats */

  public:
    /* Constructeur */
    PokemonModele(unsigned int id);

    /* Accesseurs */
    unsigned int	get_id() const;
    const std::string	&get_name() const;
  };

  std::ostream	&operator<<(std::ostream &os, const PokemonModele &pokemon);
}

#endif		/* !POKEMON_MODELE_HPP_ */
