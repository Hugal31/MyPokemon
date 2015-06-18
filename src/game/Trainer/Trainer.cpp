/*
** Trainer.cpp for MyPokemon in /home/laloge_h/projets/Perso/C++/MyPokemon/src/game/Trainer
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Thu Jun 18 14:13:43 2015 Hugo Laloge
** Last update Thu Jun 18 15:48:47 2015 Hugo Laloge
*/

#include	"game/Trainer.hpp"

using namespace	game;

Trainer::Trainer(const std::string &name, e_gender gender) :
  _gender(gender),
  _name(name),
  _current_pokemon(nullptr)
{
  for (unsigned int i = 0; i < MAX_POKEMON; i++)
    _pokemons[i] = nullptr;
}

Trainer::~Trainer()
{

}

void	Trainer::set_current_pokemon(unsigned int index)
{
  _current_pokemon = _pokemons[index];
}

bool	Trainer::lose()
{
  for (unsigned int i(0); i < MAX_POKEMON; i++)
    {
      if (_pokemons[i]->get_hp().get_value() != 0)
	return (false);
    }
  return (true);
}
