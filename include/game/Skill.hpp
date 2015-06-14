/*
** Skill.hpp for MyPokemon in /home/quief_h/rendu/MyPokemon/include/game
**
** Made by Hippolyte QUIEF
** Login   <quief_h@epitech.net>
**
** Started on  Thu Jun 11 13:16:48 2015 Hippolyte QUIEF
** Last update Sun Jun 14 22:27:24 2015 Hugo Laloge
*/

#ifndef		SKILL_HPP_
# define	SKILL_HPP_

# include	<iostream>
# include	<string>
#include    "Type.hpp"

namespace	game
{
  enum	e_skill_type
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
    Type		_type;
    unsigned int	_power;
    unsigned int	_precision;
    unsigned int	_pp;
    e_skill_type	_skill_type;

  /* Serialisation */
    template<class Archive>
    void		serialize(Archive &ar, const unsigned int version)
    {
      (void)version;
      ar & _name;
      ar & _id;
      ar & _type;
      ar & _power;
      ar & _precision;
      ar & _pp;
      ar & _skill_type;
    }

  public:
    Skill();
    //Skill();

    /* Assesseurs */
    const std::string	&get_name() const;
    unsigned int	get_id() const;
    Type		get_type() const;
    unsigned int	get_power() const;
    unsigned int	get_precision() const;
    unsigned int	get_pp() const;
    e_skill_type	get_skill_type() const;

    /*  Asseteurs */
    void		set_name(const std::string &name);
    void		set_skill_type(e_skill_type skill_type);
  };
}

std::ostream		&operator<<(std::ostream &os, const game::Skill &skill);

#endif		/* !SKILL_HPP_ */
