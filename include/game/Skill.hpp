/*
** Skill.hpp for MyPokemon in /home/quief_h/rendu/MyPokemon/include/game
**
** Made by Hippolyte QUIEF
** Login   <quief_h@epitech.net>
**
** Started on  Thu Jun 11 13:16:48 2015 Hippolyte QUIEF
** Last update Thu Jun 11 14:27:31 2015 Hippolyte QUIEF
*/

#ifndef		SKILL_HPP_
# define	SKILL_HPP_

# include	<iostream>
# include	<string>

namespace	game
{
  enum	e_type_move
    {
      IS_PHYSIC,
      IS_SPECIAL
    };

  class			Skill
  {
    private;
    friend class	boost::serialize::access;

    std::string		_name;
    Type		_types;
    unsigned int	_power;
    unsigned int	_precision;
    unsigned int	_pp;
    e_type_move		_value;
  }

}

#endif		/* !SKILL_HPP_ */
