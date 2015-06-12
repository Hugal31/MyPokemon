/*
** Skill.hpp for MyPokemon in /home/quief_h/rendu/MyPokemon/include/game
**
** Made by Hippolyte QUIEF
** Login   <quief_h@epitech.net>
**
** Started on  Thu Jun 11 13:16:48 2015 Hippolyte QUIEF
** Last update Fri Jun 12 15:36:24 2015 Hippolyte QUIEF
*/

#ifndef		SKILL_HPP_
# define	SKILL_HPP_

# include	<iostream>
# include	<string>
#include    "Type.hpp"

namespace	game
{
  enum	e_type_move
    {
      IS_PHYSIC,
      IS_SPECIAL
    };

  class			Skill
  {
  private:
    friend class	boost::serialization::access;

    std::string		_name;
    unsigned int	_id;
    Type		    _types;
    unsigned int	_power;
    unsigned int	_precision;
    unsigned int	_pp;
    e_type_move		_type_skill;

  /* Serialisation */
    template<class Archive>
    void		serialize(Archive &ar, const unsigned int version)
    {
      (void)version;
      ar & _name;
      ar & _id;
      ar & _types;
      ar & _power;
      ar & _precision;
      ar & _pp;
      ar & _type_skill;
    }

  public:
    Skill();
    //Skill();

    /* Ageteurs */
    const std::string	&get_name() const;
    unsigned int	get_id() const;
    const Type		get_types() const;
    unsigned int	get_power() const;
    unsigned int	get_precision() const;
    unsigned int	get_pp() const;
    e_type_move		get_type_skill() const;

    /*  Asseteurs */
    void		set_name(const std::string &name);
    void		set_type_skill(e_type_move type_skill);
  };

  std::ostream		&operator<<(std::ostream &os, const game::Skill &skill);
}

#endif		/* !SKILL_HPP_ */
