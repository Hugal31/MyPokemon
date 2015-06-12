/*
** Pokemon.hpp for MyPokemon in /home/quief_h/rendu/MyPokemon/include/game
**
** Made by Hippolyte QUIEF
** Login   <quief_h@epitech.net>
**
** Started on  Wed Jun 10 11:20:38 2015 Hippolyte QUIEF
** Last update Fri Jun 12 15:42:11 2015 Hippolyte QUIEF
>>>>>>> Stashed changes
*/

#ifndef		POKEMON_HPP_
# define	POKEMON_HPP_

# include	<iostream>
# include	<string>

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
    unsigned int	_id;
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

    Skill		_cap1;
    Skill		_cap2;
    Skill		_cap3;
    Skill		_cap4;

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
      ar & _cap1;
      ar & _cap2;
      ar & _cap3;
      ar & _cap4;
    }

  public:
    Pokemon();
    Pokemon(const PokemonModel &model,
	    unsigned int level = 1, e_owner owner = IS_WILD);
    virtual	 ~Pokemon();

    void	generate(const PokemonModel &model,
			  unsigned int level, e_owner owner);

    /* Ageteurs */
    const std::string	&get_nickname() const;
    unsigned int	get_id() const;
    unsigned int	get_level() const;
    e_owner		get_owner() const;
    //unsigned int	get_id_item_holding() const;
    unsigned int	get_xp() const;
    const Stat		&get_hp() const;
    const Stat		&get_atk() const;
    const Stat		&get_def() const;
    const Stat		&get_spa() const;
    const Stat		&get_spd() const;
    const Stat		&get_spe() const;
    const Skill		&get_cap1() const;
    const Skill		&get_cap2() const;
    const Skill		&get_cap3() const;
    const Skill		&get_cap4() const;

    /* Asseteurs */
    void		set_nickname(const std::string &nickname);
    void		set_owner(e_owner owner);
    // void		set_id_item_value(unsigned int id_item_holding);
  };
}

std::ostream	&operator<<(std::ostream &os, const game::Pokemon &poke);


#endif		/* !POKEMON_HPP_ */
