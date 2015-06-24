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
  bool	have_skill = false;

  for (int i = 0; i < 4; i++)
    if (_pokemon->get_skill(i) != nullptr)
    {
      have_skill = true;
      break;
    }
  if (have_skill)
  {
    Skill *selected_skill;
    while ((selected_skill = _pokemon->get_skill(distribution(generator))) != nullptr);
    selected_skill->use(*_pokemon, *opponent->get_current_pokemon());
  }
}
