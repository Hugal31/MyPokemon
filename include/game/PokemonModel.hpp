/*
** PokemonModel.hpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue May 26 15:26:57 2015 Hugo Laloge
** Last update Mon Jun 15 16:21:51 2015 Hugo Laloge
*/

#ifndef		POKEMON_MODEL_HPP_
# define	POKEMON_MODEL_HPP_

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

namespace game
{
  /*
  ** @brief	Classe modele pour pokemon ayant pour but de pouvoir etre
  **		sérialisé et modifié facilement
  */
  class			PokemonModel
  {
  protected:
    friend class	boost::serialization::access;

    std::string		_name;
    std::string		_species;
    std::string		_resum;
    Type		_types[2];
    unsigned int	_id;
    unsigned int	_max_xp;
    unsigned short int	_heigth;
    unsigned short int	_weight;
    unsigned short int	_catch_rate;
    unsigned short int	_gender_rate;

    StatModel		_hp;
    StatModel		_atk;
    StatModel		_def;
    StatModel		_spa;
    StatModel		_spd;
    StatModel		_spe;

    /* Serialisation */

    template<class Archive>
    void		serialize(Archive &ar, const unsigned int version)
    {
      (void)version;
      ar & _id;
      ar & _name;
      ar & _species;
      ar & _types;
      ar & _max_xp;
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
    }

  public:
    /* Liste de tous les pokemons modeles */
    static std::vector<PokemonModel>	pokedex;
    static void	init_pokedex();

    /* Constructeur */
    PokemonModel(unsigned int id = 0);

    /* Accesseurs */
    const std::string	&get_name() const;
    const std::string	&get_species() const;
    const std::string	&get_resum() const;
    const Type		*get_types() const;
    unsigned int	get_id() const;
    unsigned int	get_max_xp() const;
    unsigned short int	get_heigth() const;
    unsigned short int	get_weight() const;
    unsigned short int	get_catch_rate() const;
    unsigned short int	get_gender_rate() const;
    const StatModel	&get_hp() const;
    const StatModel	&get_atk() const;
    const StatModel	&get_def() const;
    const StatModel	&get_spa() const;
    const StatModel	&get_spd() const;
    const StatModel	&get_spe() const;

    /* Assesseurs */
    void	        set_name(const std::string &name);
    void		set_species(const std::string &species);
    void		set_resum(const std::string &resum);
    void		set_types(const Type &type1, const Type &type2);
    void		set_types(const std::string &type1, const std::string &type2);
    void		set_max_xp(unsigned int max_xp);
    void		set_heigth(unsigned short int heigth);
    void		set_weight(unsigned short int weight);
    void		set_catch_rate(unsigned short int catch_rate);
    void		set_gender_rate(unsigned short int gender_rate);
  };

  std::ostream	&operator<<(std::ostream &os, const PokemonModel &pokemon);
}

NO_WARNINGS
BOOST_CLASS_VERSION(game::PokemonModel, 0)
WARNINGS

#endif		/* !POKEMON_MODEL_HPP_ */
