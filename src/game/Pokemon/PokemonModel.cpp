/*
** PokemonModel.cpp
** Created by laloge_h on 18 juin 06:08 2015.
*/

#include	<fstream>
#include	<ostream>
#include	<string>
#include	<vector>
#include	"game/id.hpp"
#include	"game/PokemonModel.hpp"

using namespace	game;

std::array<PokemonModel*, MAX_POKEMON_ID>	PokemonModel::pokedex;

PokemonModel::PokemonModel(unsigned int id) :
  _id(id), _xp_type(XP_ERRATIC), _heigth(10), _weight(10),
  _catch_rate(50), _gender_rate(50), _hp(true)
{
  //Ouvrir le fichier/DB et parser les infos ?
}

namespace
{
  std::string	get_file_name(Id id)
  {
    return ("ressources/pokemon/" + std::to_string(id) + ".poke");
  }
}

/*
** Initialisation de la liste de pokemon
*/

void	PokemonModel::init_pokedex()
{
  Id	id(1);

  pokedex[0] = nullptr;
  while (id < MAX_POKEMON_ID)
    {
      std::ifstream	file(get_file_name(id));
      if (file)
	{
	  PokemonModel	*model;
	  model = new PokemonModel;
	  boost::archive::text_iarchive	ia(file);
	  ia >> *model;
	  pokedex[id] = model;
	}
      else
        pokedex[id] = nullptr;
      id++;
    }
}

/*
** Accesseurs
*/

const std::string	&PokemonModel::get_name() const
{
  return (_name);
}

const std::string	&PokemonModel::get_species() const
{
  return (_species);
}

const std::string	&PokemonModel::get_resum() const
{
  return (_resum);
}

const Type	*PokemonModel::get_types() const
{
  return (_types);
}

unsigned int	PokemonModel::get_id() const
{
  return (_id);
}

e_xp_type	PokemonModel::get_xp_type() const
{
  return (_xp_type);
}

unsigned short int	PokemonModel::get_heigth() const
{
  return (_heigth);
}

unsigned short int	PokemonModel::get_weight() const
{
  return (_weight);
}

unsigned short int	PokemonModel::get_catch_rate() const
{
  return (_catch_rate);
}

unsigned short int	PokemonModel::get_gender_rate() const
{
  return (_gender_rate);
}

const StatModel	&PokemonModel::get_hp() const
{
  return (_hp);
}

const StatModel	&PokemonModel::get_atk() const
{
  return (_atk);
}

const StatModel	&PokemonModel::get_def() const
{
  return (_def);
}

const StatModel	&PokemonModel::get_spa() const
{
  return (_spa);
}

const StatModel	&PokemonModel::get_spd() const
{
  return (_spd);
}

const StatModel	&PokemonModel::get_spe() const
{
  return (_spe);
}

unsigned short int	PokemonModel::get_xp_base() const
{
  return (_xp_base);
}

/*
** Asseteurs
*/

void	PokemonModel::set_name(const std::string &name)
{
  _name = name;
}

void	PokemonModel::set_species(const std::string &species)
{
  _species = species;
}

void	PokemonModel::set_resum(const std::string &resum)
{
  _resum = resum;
}

void	PokemonModel::set_types(const Type &type1, const Type &type2)
{
  _types[0] = type1;
  _types[1] = type2;
}

void	PokemonModel::set_types(const std::string &type1,
				const std::string &type2)
{
  _types[0].set_value(type1);
  _types[1].set_value(type2);
}

void	PokemonModel::set_xp_type(const e_xp_type xp_type)
{
  _xp_type = xp_type;
}

void	PokemonModel::set_heigth(const unsigned short int heigth)
{
  _heigth = heigth;
}

void	PokemonModel::set_weight(const unsigned short int weight)
{
  _weight = weight;
}

void	PokemonModel::set_catch_rate(const unsigned short int catch_rate)
{
  _catch_rate = catch_rate;
}

void	PokemonModel::set_gender_rate(const unsigned short int gender_rate)
{
  _gender_rate = gender_rate;
}


void	PokemonModel::set_xp_base(unsigned short int xp_base)
{
  _xp_base = xp_base;
}

/*
** Surcharge externes
*/

std::ostream	&game::operator<<(std::ostream &os, const PokemonModel &pokemon)
{
  os << "Id : " << pokemon.get_id() << std::endl
     << "Name : " << pokemon.get_name() << std::endl
     << "Resum : " << pokemon.get_resum() << std::endl
     << "Species : " << pokemon.get_species() << std::endl
     << "Types : " << pokemon.get_types()[0] << " and "
     << pokemon.get_types()[1] << std::endl
     << "Max xp : " << pokemon.get_xp_type() << std::endl
     << "Heigth : " << pokemon.get_heigth() << std::endl
     << "Weight : " << pokemon.get_weight() << std::endl
     << "Catch rate : " << pokemon.get_catch_rate() << std::endl
     << "Gender rate : " << pokemon.get_gender_rate() << std::endl;
  return (os);
}
