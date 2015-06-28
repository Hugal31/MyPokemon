/*
** WildTrainer.cpp
** Created by laloge_h on 18 juin 06:43 2015.
*/

#include	<random>
#include	<stdexcept>
#include	<string>
#include	"game/Combat.hpp"
#include	"game/WildTrainer.hpp"

using namespace	game;

WildTrainer::WildTrainer(Pokemon *pokemon) :
  _pokemon(pokemon)
{
}

WildTrainer::WildTrainer(Id id, unsigned int level)
{
  (void)level;
  if (PokemonModel::pokedex[id] == nullptr)
    throw std::invalid_argument("Pokemon " + std::to_string(id) + " not defined");
  else
    _pokemon = new Pokemon(*PokemonModel::pokedex[id], level);
}

WildTrainer::~WildTrainer()
{
  delete _pokemon;
}

void	WildTrainer::init_pokemons()
{
  _pokemon->init_stats();
}

/**
 * @brief	Retourn vrai si le pokemon n'a plus de HP.
 *		La fuite n'est pas admise !
 */
bool	WildTrainer::lose()
{
  return (_pokemon->get_hp().get_value() == 0);
}

Pokemon *WildTrainer::get_current_pokemon()
{
  return _pokemon;
}

void  WildTrainer::play(Combat *fight, AbstractTrainer *opponent)
{
  std::default_random_engine	generator;
  std::uniform_int_distribution<unsigned int>	distribution(0, 3);

  if (!_pokemon->get_skills().empty())
  {
    Skill *selected_skill;
    while ((selected_skill = _pokemon->get_skill(distribution(generator))) == nullptr);
    std::cout << _pokemon->get_nickname() << " utilise "
	      << selected_skill->get_name() << std::endl;
    switch (selected_skill->use(*_pokemon, *opponent->get_current_pokemon()))
    {
    case RESULT_FAIL:
      std::cout << "Mais il rate !";
      break;

    case RESULT_NO_ENOUGH_PP:
      std::cout << "Pas assez de PP";
      break;

    case RESULT_SUCCESS:
      std::cout << "Il reussit";
      break;

    case RESULT_VERY_EFFECTIVE:
      std::cout << "C'est tres efficace !";
      break;

    case RESULT_NOT_EFFECTIVE:
      std::cout << "Ce n'est pas tres efficace...";
      break;
    }
    std::cin.get();
  }
}
