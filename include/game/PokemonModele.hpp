/*
** PokemonModele.hpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue May 26 15:26:57 2015 Hugo Laloge
** Last update Tue May 26 16:08:54 2015 Hugo Laloge
*/

#ifndef		POKEMON_MODELE_HPP_
# define	POKEMON_MODELE_HPP_

# include	<iostream>
# include	<string>

namespace game
{
  class			PokemonModele
  {
    const unsigned int	_id;
    std::string		_name;

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
