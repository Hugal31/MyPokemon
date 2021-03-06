/*
** Combat.cpp
** Created by laloge_h on 18 juin 05:59 2015.
*/

#include	<iostream>
#include	"game/Combat.hpp"
#include	"game/Pokemon.hpp"

using namespace game;

Combat::Combat(AbstractTrainer *trainer1, AbstractTrainer *trainer2) :
  _nb_turn(0),
  _weather(WEATHER_CLEAR),
  _play(OWN_PLAY)
{
  _trainers[0] = trainer1;
  _trainers[1] = trainer2;
}

Combat::~Combat()
{

}

void  Combat::display_combat_info()
{
  system("clear");
  std::cout << "Your Pokemon" << "\t\t\t" << "Opponent's Pokemon" << std::endl
  << _trainers[0]->get_current_pokemon()->get_nickname() << "\t\t\t"
  << _trainers[1]->get_current_pokemon()->get_nickname() << std::endl
  << "Level : " << _trainers[0]->get_current_pokemon()->get_level() << "\t\t\t"
  << "Level : " << _trainers[1]->get_current_pokemon()->get_level() << std::endl
  << "Hp : " << _trainers[0]->get_current_pokemon()->get_hp().get_value() << "\t\t\t\t"
  << "Hp : " << _trainers[1]->get_current_pokemon()->get_hp().get_value() << std::endl;
}

/**
 * @brief	Lance le combat
 *
 * @return	Renvoie le gagnant
 */
e_play		Combat::start()
{
  e_play	current_trainer = OWN_PLAY;

  _trainers[0]->init_pokemons();
  _trainers[1]->init_pokemons();
  display_combat_info();
  while (!_trainers[0]->lose() && !_trainers[1]->lose())
  {
    _trainers[current_trainer]->play(this, _trainers[(current_trainer + 1) % 2]);
    current_trainer = static_cast<e_play>((current_trainer + 1) % 2);
    display_combat_info();
  }
  return ((!_trainers[0]->lose()) ? OWN_PLAY : OTHER_PLAY);
}

/*
** Accesseurs
*/

unsigned int        Combat::get_nb_turn() const
{
  return (_nb_turn);
}

e_weather        Combat::get_weather() const
{
  return (_weather);
}

e_play        Combat::get_play() const
{
  return (_play);
}

/*
** Asseteurs
*/

void        Combat::set_weather(e_weather weather)
{
  _weather = weather;
}

void        Combat::set_play(e_play play)
{
  _play = play;
}

/*
** Surcharge operateur
*/

std::ostream &operator<<(std::ostream &os, const Combat &fight)
{
  os << "Nombre Tours" << fight.get_nb_turn() << std::endl
  << "Temps" << fight.get_weather() << std::endl
  << "Joueur" << fight.get_play() << std::endl
    // << "Notre Pokemon" << << std::endl
    // << "Pokemon adv" << << std::endl
    ;
  return (os);
}

/*
** Fonction
*/

unsigned int xp_gain(Pokemon &poke, Pokemon &poke_adv)
{
  (void) poke;
  unsigned int xp;
  unsigned int e;  //Lucky egg
  float a;
  float s;  //xp_share, pokemon on the battle etc... cf poke_doc/xp.info

  a = (poke_adv.get_owner() == IS_WILD) ? 1 : 1.5;
  e = 1;
  s = 1.0;
  xp = static_cast<unsigned int>(((a * PokemonModel::pokedex[poke_adv.get_id()]->get_xp_base()
				   * poke_adv.get_level()) / static_cast<unsigned int>(5 * s))
				 * (static_cast<unsigned int>(std::pow((2 * poke_adv.get_level()), 2.5) + 1) * e));
  return (xp);
}
