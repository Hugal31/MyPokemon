/*
** Trainer.cpp for MyPokemon in /home/laloge_h/projets/Perso/C++/MyPokemon/src/game/Trainer
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Thu Jun 18 14:13:43 2015 Hugo Laloge
** Last update Thu Jun 18 14:17:31 2015 Hugo Laloge
*/

#include	"game/Trainer.hpp"

using namespace	game;

Trainer::Trainer(const std::string &name, e_gender gender) :
  _gender(gender),
  _name(name)
{

}

Trainer::~Trainer()
{

}
