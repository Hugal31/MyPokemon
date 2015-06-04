/*
** Item.cpp for MyPokemon in /home/quief_h/rendu/MyPokemon/src/game/Item
**
** Made by Hippolyte QUIEF
** Login   <quief_h@epitech.net>
**
** Started on  Thu Jun  4 10:35:57 2015 Hippolyte QUIEF
** Last update Thu Jun  4 10:55:23 2015 Hippolyte QUIEF
*/


#include	<ostream>
#include	<string>
#include	"game/PokemonModele.hpp"

using namespace	game;

Item::Item(unsigned int id) :
  _id(id), _buy_value(0), _sell_value(0)
{
  //Ouvrir le fichier/DB et parser les infos
}

Item::~Item()
{

}

/*
** Accesseurs
*/

const std::string	&Item::get_name() const
{
  return (_name);
}

const std::string	&Item::get_resum() const
{
  return (_resum);
}

e_item_type		&Item::get_type() const
{
  return (_type);
}

unsigned int		&Item::get_id() const
{
  return (_id);
}

unsigned int		&Item::get_buy_value() const
{
  return (_buy_value);
}
unsigned int		&Item::get_sell_value() const
{
  return (_sell_value);
}
/*
** Assesseurs
*/

void		Item::set_name(const std::string &name)
{
  _name = name;
}

void		Item::set_resum(const std::string &resum)
{
  _resum = resum;
}

void		Item::set_type(e_item_type &type)
{
  _type = type;
}

void		Item::set_id(unsigned int &id)
{
  _id = id;
}

void		Item::set_buy_value(unsigned int &buy_value)
{
  _buy_value = buy_value;
}

void		Item::set_sell_value(unsigned int &sell_value)
{
  _sell_value = sell_value;
}

/*
** Surcharge externes
*/

std::ostream	&game::operator<<(std::ostream &os, const PokemonModele &pokemon)
{
  os << "Id : " << pokemon.get_id() << std::endl
     << "Name : " << pokemon.get_name() << std::endl
     << "Resum : " << pokemon.get_resum() << std::endl
     << "Type : " << pokemon.get_type() << std::endl
     << "Buy Value : " << pokemon.get_buy_value() << std::endl
     << "Sell Value : " << pokemon.get_sell_value() << std::endl;
  return (os);
