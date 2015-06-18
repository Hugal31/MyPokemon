/*
** main.cpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue May 26 15:55:50 2015 Hugo Laloge
** Last update Thu Jun 18 12:56:10 2015 Hugo Laloge
*/

#include	<array>
#include	<cstdlib>
#include	<iostream>
#include	"game/PokemonModel.hpp"

namespace
{
  void	init_game()
  {
    game::PokemonModel::init_pokedex();
    for (std::array<game::PokemonModel*, MAX_POKEMON>::iterator i = game::PokemonModel::pokedex.begin() + 1;
	 i != game::PokemonModel::pokedex.end();
	 i++)

      {
	if (*i != nullptr)
	  std::cout << **i << std::endl;
      }
  }
}

int	main(void)
{
  int	ret;

  init_game();
  ret = EXIT_SUCCESS;
  return (ret);
}
