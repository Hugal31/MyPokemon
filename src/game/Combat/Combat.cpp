/*
** Combat.cpp for MyPokemon in /home/quief_h/rendu/MyPokemon/src/game/Combat
**
** Made by Hippolyte QUIEF
** Login   <quief_h@epitech.net>
**
** Started on  Tue Jun 16 11:20:57 2015 Hippolyte QUIEF
** Last update Tue Jun 16 11:21:17 2015 Hippolyte QUIEF
*/

#include        <iostream>
#include        "game/Combat.hpp"

using namespace game;

Combat::Combat() :
    _nb_turn(0),
    _weather(WEATHER_CLEAR),
    _play(OWN_PLAY)
{

}

Combat::~Combat()
{
}

/*
** Ageteurs
*/

unsigned int    Combat::get_nb_turn() const
{
    return (_nb_turn);
}

e_weather       Combat::get_weather() const
{
    return (_weather);
}

e_play          Combat::get_play() const
{
    return (_play);
}

const Pokemon   *Combat::get_own_pokemon() const
{
    return (_own_pokemon);
}

const Pokemon   *Combat::get_other_pokemon() const
{
    return (_other_pokemon);
}

/*
** Asseteurs
*/

void    Combat::set_weather(e_weather weather)
{
    _weather = weather;
}

void    Combat::set_play(e_play play)
{
    _play = play;
}

/*
** Surcharge operateur
*/

std::ostream    &operator<<(std::ostream &os, const Combat &fight)
{
    os  << "Nombre Tours" << fight.get_nb_turn() << std::endl
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

unsigned int    xp_gain(Pokemon &poke, Pokemon &poke_adv)
{
    unsigned int         xp;
    float       a;
    int         e;  //Lucky egg
    float       s;  //xp_share, pokemon on the battle etc... cf poke_doc/xp.info

    if (poke_adv.get_owner() == IS_WILD)
        a = 1;
    else
        a = 1.5;
    e = 1;
    s = 1;
    xp = ((a * PokemonModel::pokedex[poke_adv.get_id()].get_xp_base() * poke_adv.get_level()) / (5 * s)) * ((std::pow((2 * poke_adv.get_level()), 2.5) + 1) * e);
    return (xp);
}