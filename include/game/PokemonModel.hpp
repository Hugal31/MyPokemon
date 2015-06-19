/*
** PokemonModel.hpp
** Created by laloge_h on 18 juin 06:01 2015.
*/

#ifndef		POKEMON_MODEL_HPP_
# define	POKEMON_MODEL_HPP_

# include	<array>
# include	<iostream>
# include	<string>
# include	<vector>

# include	"no_warnings.hpp"

NO_WARNINGS

# include	<boost/archive/text_oarchive.hpp>
# include	<boost/archive/text_iarchive.hpp>

WARNINGS

# include	"Type.hpp"
# include	"StatModel.hpp"
# include	"xp.hpp"

# ifdef	EDITOR
#  include	"PokeEditWidget.hpp"
# endif	/* EDITOR */

# define	MAX_POKEMON_ID	151

namespace game
{
  /*
  ** @brief	Classe modele pour pokemon ayant pour but de pouvoir etre
  **		sérialisé et modifié facilement
  */
  class			PokemonModel
  {
  protected:
# ifdef	EDITOR
    friend class	ui::PokeEditWidget;
# endif	/* EDITOR */
    friend class	boost::serialization::access;

    std::string		    _name;
    std::string		    _species;
    std::string		    _resum;
    Type		        _types[2];
    /* Pourquoi stocker l'id ? */
    unsigned int	    _id;
    e_xp_type		    _xp_type;
    unsigned short int	_heigth;
    unsigned short int	_weight;
    unsigned short int	_catch_rate;
    unsigned short int	_gender_rate;
    //map_localisation

    StatModel		    _hp;
    StatModel		    _atk;
    StatModel		    _def;
    StatModel		    _spa;
    StatModel		    _spd;
    StatModel		    _spe;
    unsigned short int	_xp_base;

    /* Serialisation */

    template<class Archive>
    void		serialize(Archive &ar, const unsigned int version)
    {
      (void)version;
      ar & _id;
      ar & _name;
      ar & _species;
      ar & _resum;
      ar & _types;
      ar & _xp_type;
      ar & _heigth;
      ar & _weight;
      ar & _catch_rate;
      ar & _gender_rate;
      ar & _hp;
      ar & _atk;
      ar & _def;
      ar & _spa;
      ar & _spd;
      ar & _spe;
      ar & _xp_base;
    }

  public:
    /* Liste de tous les pokemons modeles */
    static std::array<PokemonModel*, MAX_POKEMON_ID>	pokedex;
    static void	init_pokedex();

    /* Constructeur */
    PokemonModel(unsigned int id = 0);

    /* Accesseurs */
    const std::string	&get_name() const;
    const std::string	&get_species() const;
    const std::string	&get_resum() const;
    const Type		    *get_types() const;
    unsigned int	    get_id() const;
    e_xp_type		    get_xp_type() const;
    unsigned short int	get_heigth() const;
    unsigned short int	get_weight() const;
    unsigned short int	get_catch_rate() const;
    unsigned short int	get_gender_rate() const;
    const StatModel	    &get_hp() const;
    const StatModel	    &get_atk() const;
    const StatModel	    &get_def() const;
    const StatModel	    &get_spa() const;
    const StatModel	    &get_spd() const;
    const StatModel	    &get_spe() const;
    unsigned short int	get_xp_base() const;

    /* Assesseurs */
    void		set_name(const std::string &name);
    void		set_species(const std::string &species);
    void		set_resum(const std::string &resum);
    void		set_types(const Type &type1, const Type &type2);
    void		set_types(const std::string &type1, const std::string &type2);
    void		set_xp_type(e_xp_type xp_type);
    void		set_heigth(unsigned short int heigth);
    void		set_weight(unsigned short int weight);
    void		set_catch_rate(unsigned short int catch_rate);
    void		set_gender_rate(unsigned short int gender_rate);
    void		set_xp_base(unsigned short int xp_base);
  };

  std::ostream	&operator<<(std::ostream &os, const PokemonModel &pokemon);
}

NO_WARNINGS
BOOST_CLASS_VERSION(game::PokemonModel, 0)
WARNINGS

#endif		/* !POKEMON_MODEL_HPP_ */
