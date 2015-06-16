/*
** Combat.hpp for MyPokemon in /home/quief_h/rendu/MyPokemon
**
** Made by Hippolyte QUIEF
** Login   <quief_h@epitech.net>
**
** Started on  Tue Jun 16 11:56:41 2015 Hippolyte QUIEF
** Last update Tue Jun 16 11:56:52 2015 Hippolyte QUIEF
*/

#ifndef		COMBAT_HPP_
# define	COMBAT_HPP_

# include	<iostream>
# include	<string>

NO_WARNINGS

# include	<boost/archive/text_oarchive.hpp>
# include	<boost/archive/text_iarchive.hpp>

WARNINGS

#include    "Pokemon.hpp"

int         xp_gain(Pokemon &poke, Pokemon &poke_adv);

#endif		/* !COMBAT_HPP_ */
