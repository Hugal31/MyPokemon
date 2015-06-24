/*
** WildTrainer.cpp
** Created by laloge_h on 18 juin 06:43 2015.
*/


#include	<stdexcept>
#include	<string>
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

/*
** @brief	Retourn vrai si le pokemon n'a plus de HP.
**		La fuite n'est pas admise !
*/
bool	WildTrainer::lose()
{
  return (_pokemon->get_hp().get_value() == 0);
}
