/*
** Skill.hpp
** Created by laloge_h on 18 juin 06:03 2015.
*/

#ifndef		SKILL_HPP_
# define	SKILL_HPP_

namespace	game
{
  class		Pokemon;
}

# include	<iostream>
# include	<string>
# include	"Type.hpp"

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

    virtual unsigned int	calc_dammage(const Pokemon &user,
					     const Pokemon &target);

  public:
    Skill();
    virtual		~Skill();

    virtual int		use(Pokemon &user, Pokemon &target);

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
