/*
** main.cpp
** Created by laloge_h on 18 juin 06:12 2015.
*/

#include	<array>
#include	<cstdlib>
#include	<iostream>
#include	"game/Combat.hpp"
#include	"game/Player.hpp"
#include	"game/PokemonModel.hpp"
#include        "game/Type.hpp"
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
    game::WildTrainer	wild(2, 5);
    game::Player	player("Sacha");
    game::Pokemon	player_pokemon(*game::PokemonModel::pokedex[1], 5, game::IS_OWN);
    game::Skill		charge;

    charge.set_name("Charge");
    charge.set_id(33);
    charge.set_type(game::TYPE_NORMAL);
    charge.set_power(50);
    charge.set_pp(35);
    charge.set_precision(100);
    charge.set_skill_type(game::IS_PHYSIC);

    player_pokemon.set_skill(0, new game::Skill(charge));
    player.set_pokemon(&player_pokemon, 0);
    player.set_current_pokemon(0);
    wild.get_current_pokemon()->set_skill(0, new game::Skill(charge));
    game::Combat	fight(&player, &wild);
    switch (fight.start())
      {
      case game::OWN_PLAY:
	std::cout << "Vous avez gagné !";
	break;
      case game::OTHER_PLAY:
	std::cout << "Vous avez perdu !";
	  break;
      }
    std::cout << std::endl;
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
