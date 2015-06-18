/*
** main.cpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue May 26 15:55:50 2015 Hugo Laloge
** Last update Thu Jun 18 15:37:32 2015 Hugo Laloge
*/

#include	<array>
#include	<cstdlib>
#include	<iostream>
#include	"game/Combat.hpp"
#include	"game/Player.hpp"
#include	"game/PokemonModel.hpp"
#include	"game/WildTrainer.hpp"

namespace
{
  void	init_game()
  {
    game::PokemonModel::init_pokedex();
    for (std::array<game::PokemonModel*, MAX_POKEMON_ID>::iterator i = game::PokemonModel::pokedex.begin() + 1;
	 i != game::PokemonModel::pokedex.end();
	 i++)

      {
	if (*i != nullptr)
	  std::cout << **i << std::endl;
      }
  }

  void	combat_test()
  {
    game::WildTrainer	wild(1, 5);
    game::Player	player("Sacha");
    player.set_pokemon(new game::Pokemon(*game::PokemonModel::pokedex[1], 5, game::IS_OWN), 0);
    player.set_current_pokemon(0);
    game::Combat	fight(&player, &wild);
    fight.start();
  }
}

int	main(void)
{
  int	ret;

  init_game();
  combat_test();
  ret = EXIT_SUCCESS;
  return (ret);
}
