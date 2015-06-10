/*
** Pokemon.hpp for MyPokemon in /home/quief_h/rendu/MyPokemon/include/game
**
** Made by Hippolyte QUIEF
** Login   <quief_h@epitech.net>
**
** Started on  Wed Jun 10 11:20:38 2015 Hippolyte QUIEF
** Last update Wed Jun 10 13:42:59 2015 Hippolyte QUIEF
*/

#ifndef		POKEMON_HPP_
# define	POKEMON_HPP_

# include	<iostream>
# include	<string>

# include	"game/PokemonModele.hpp"
# include	"game/Type.hpp"
# include	"game/Stat.hpp"

namespace	game
{
  enum	e_catch
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
    e_catch		_value;
    //unsigned int	_id_item_holding;
    unsigned int	_xp;

    Stat		_hp;
    Stat		_atk;
    Stat		_def;
    Stat		_spa;
    Stat		_spd;
    Stat		_spe;

    /* Serialisation */

    template<class Archive>
    void		serialize(Archive &ar, const unsigned int version)
    {
      (void)version;
      ar & _nickname;
      ar & _id;
      ar & _level;
      ar & _value;
      //ar & _id_item_holding;
      ar & _xp;
      ar & _hp;
      ar & _atk;
      ar & _def;
      ar & _spa;
      ar & _spd;
      ar & _spe;
    }

  public:
    Pokemon(const PokemonModele &model);
    virtual	 ~Pokemon();

    /* Ageteurs */
    const std::string	&get_nickname() const;
    unsigned int	get_id() const;
    unsigned int	get_level() const;
    e_catch		get_value() const;
    //unsigned int	get_id_item_holding() const;
    unsigned int	get_xp() const;
    const Stat		&get_hp() const;
    const Stat		&get_atk() const;
    const Stat		&get_def() const;
    const Stat		&get_spa() const;
    const Stat		&get_spd() const;
    const Stat		&get_spe() const;

    /* Aseteurs */
    void		set_nickname(const std::string &nickname);
    void		set_catch_value(e_catch value);
    // void		set_id_item_value(unsigned int id_item_holding);
  };

  std::ostream	&operator<<(std::ostream &os, const Pokemon &poke);
}

#endif		/* !POKEMON_HPP_ */
