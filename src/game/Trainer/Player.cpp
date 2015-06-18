/*
** Player.cpp for MyPokemon in /home/laloge_h/rendu/MyPokemon/src/game/Player
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Thu Jun 18 12:58:12 2015 Hugo Laloge
** Last update Thu Jun 18 14:16:26 2015 Hugo Laloge
*/

#include	<limits>
#include	<random>
#include	"game/Player.hpp"

using namespace	game;

Player::Player(const std::string &name, e_gender gender) :
  Trainer(name, gender)
{
  std::default_random_engine generator;
  std::uniform_int_distribution<Id> id_distrib(10000,
					       std::numeric_limits<unsigned short int>::max());
  std::uniform_int_distribution<Id> secret_id_distrib(0,
						      std::numeric_limits<unsigned int>::max());

  _id = id_distrib(generator);
  _secret_id = secret_id_distrib(generator);
  for (unsigned int i = 0; i < MAX_POKEMON; i++)
    _pokemons[i] = nullptr;
}

Player::~Player()
{

}
