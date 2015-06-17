/*
** main.cpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue May 26 15:55:50 2015 Hugo Laloge
** Last update Mon Jun 15 01:01:47 2015 Hugo Laloge
*/

#include	<cstdlib>
#include	<iostream>
#include	"game/PokemonModel.hpp"
#include    "game/Combat.hpp"

namespace
{
  void	init_game()
  {
    game::PokemonModel::init_pokedex();
    std::cout << "Initialisation terminée" << std::endl;
    for (std::vector<game::PokemonModel>::iterator i(game::PokemonModel::pokedex.begin() + 1);
	 i != game::PokemonModel::pokedex.end();
	 i++)
      {
	std::cout << *i << std::endl;
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
