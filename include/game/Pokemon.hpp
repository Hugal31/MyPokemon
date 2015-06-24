/*
** Pokemon.hpp
** Created by laloge_h on 18 juin 06:00 2015.
*/

#ifndef		POKEMON_HPP_
# define	POKEMON_HPP_

class ar;

# include	<iostream>
# include	<string>

# include	"game/id.hpp"
# include	"game/PokemonModel.hpp"
# include	"game/Type.hpp"
# include	"game/Stat.hpp"
# include	"game/Skill.hpp"

namespace	game
{
  enum	e_owner
    {
      IS_WILD,
      IS_TRAINER,
      IS_OWN
    };

  class			Pokemon
  {
  protected:
    friend class	boost::serialization::access;

    std::string		_nickname;
    Id			_id;
    unsigned int	_level;
    e_owner		_owner;
    //unsigned int	_id_item_holding;
    unsigned int	_xp;

    StatHp		_hp;
    Stat		_atk;
    Stat		_def;
    Stat		_spa;
    Stat		_spd;
    Stat		_spe;

    Skill		_skills[4];

    /* Serialisation */

    template<class Archive>
    void		serialize(Archive &ar, const unsigned int version)
    {
      (void)version;
      ar & _nickname;
      ar & _id;
      ar & _level;
      ar & _owner;
      //ar & _id_item_holding;
      ar & _xp;
      ar & _hp;
      ar & _atk;
      ar & _def;
      ar & _spa;
      ar & _spd;
      ar & _spe;
      ar & _skills;
    }

  public:
    Pokemon();
    Pokemon(const PokemonModel &model,
	    unsigned int level = 1, e_owner owner = IS_WILD);
    virtual	 ~Pokemon();

    void	generate(const PokemonModel &model,
			 unsigned int level, e_owner owner);

    /* Ageteurs */
    const std::string	    &get_nickname() const;
    Id			    get_id() const;
    unsigned int	    get_level() const;
    e_owner		    get_owner() const;
    //unsigned int	    get_id_item_holding() const;
    unsigned int	    get_xp() const;
    const Stat		    &get_hp() const;
    const Stat		    &get_atk() const;
    const Stat		    &get_def() const;
    const Stat		    &get_spa() const;
    const Stat		    &get_spd() const;
    const Stat		    &get_spe() const;
    unsigned int	    get_atk_value() const;
    unsigned int	    get_def_value() const;
    unsigned int	    get_spa_value() const;
    unsigned int	    get_spd_value() const;
    unsigned int	    get_spe_value() const;
    const Skill		    *get_skills() const;

    /* Asseteurs */
    void		set_nickname(const std::string &nickname);
    void		set_owner(e_owner owner);
    // void		set_id_item_value(unsigned int id_item_holding);
  };
}

std::ostream	&operator<<(std::ostream &os, const game::Pokemon &poke);


#endif		/* !POKEMON_HPP_ */
