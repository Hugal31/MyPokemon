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

namespace
{
  void	display_skills(Pokemon &poke)
  {
    std::cout << "Skills : " << std::endl;
    for (unsigned int i = 0; i < 4; i++)
      if (poke.get_skill(i) != nullptr)
	std::cout << i + 1 << " : " << poke.get_skill(i)->get_name() << std::endl;
  }
}

void	Player::play(Combat *fight, AbstractTrainer *opponent)
{
  display_skills(*get_current_pokemon());
  unsigned int	cmd = 0;
  while (1)
  {
    if ((std::cin >> cmd).fail() or cmd == 0 or cmd > 4)
      std::cerr << "Out of range" << std::endl;
    else if (get_current_pokemon()->get_skill(cmd - 1) == nullptr)
      std::cerr << "Not a skill" << std::endl;
    else
      break;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  Skill *skill = get_current_pokemon()->get_skill(cmd - 1);
  std::cout << get_current_pokemon()->get_nickname() << " utilise " << skill->get_name() << std::endl;
  skill->use(*get_current_pokemon(), *opponent->get_current_pokemon());
}
