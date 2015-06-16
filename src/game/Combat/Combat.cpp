/*
** Combat.cpp for MyPokemon in /home/quief_h/rendu/MyPokemon/src/game/Combat
**
** Made by Hippolyte QUIEF
** Login   <quief_h@epitech.net>
**
** Started on  Tue Jun 16 11:20:57 2015 Hippolyte QUIEF
** Last update Tue Jun 16 11:21:17 2015 Hippolyte QUIEF
*/

#include        "Combat.hpp"
#include        "Pokemon.hpp"

int         xp_gain(Pokemon &poke, Pokemon &poke_adv)
{
    int     xp;
    float   a;
    int     e;  //Lucky egg
    float   s;  //xp_share, pokemon on the battle etc... cf poke_doc/xp.info

    if (poke_adv.get_owner() == IS_WILD)
        a = 1;
    else
        a = 1.5;
    e = 1;
    s = 1;
    xp = ((a * PokemonModele::pokedex[poke_adv.get_id()] * pokev_adv.get_level()) / (5 * s)) * ((std::pow((2 * poke_adv.get_level()) * 2.5) + 1) * e);
    return (xp);
}