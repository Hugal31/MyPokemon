/*
** Trainer.cpp
** Created by laloge_h on 18 juin 06:10 2015.
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
