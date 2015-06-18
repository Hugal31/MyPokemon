/*
** WildTrainer.cpp for MyPokemon in /home/laloge_h/rendu/MyPokemon/src/game/Player
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Thu Jun 18 13:52:16 2015 Hugo Laloge
** Last update Thu Jun 18 15:49:02 2015 Hugo Laloge
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
