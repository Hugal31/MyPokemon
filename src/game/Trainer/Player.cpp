/*
** Player.cpp
** Created by laloge_h on 18 juin 06:10 2015.
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
}

Player::~Player()
{

}

void	Player::set_pokemon(Pokemon *pokemon, unsigned int index)
{
  _pokemons[index] = pokemon;
}

void	Player::play(Combat *fight, AbstractTrainer *opponent)
{
  std::string	cmd;
  std::cin >> cmd;
  std::cin.clear();
  (void)fight;
  (void)opponent;
}
