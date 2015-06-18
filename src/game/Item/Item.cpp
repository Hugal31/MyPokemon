/*
** Item.cpp
** Created by laloge_h on 18 juin 06:07 2015.
*/

#include	<ostream>
#include	<string>
#include	"game/PokemonModel.hpp"
#include	"game/Item.hpp"

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

e_item_type		Item::get_type() const
{
  return (_type);
}

unsigned int		Item::get_id() const
{
  return (_id);
}

unsigned int		Item::get_buy_value() const
{
  return (_buy_value);
}

unsigned int		Item::get_sell_value() const
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

void		Item::set_type(e_item_type type)
{
  _type = type;
}

void		Item::set_buy_value(unsigned int buy_value)
{
  _buy_value = buy_value;
}

void		Item::set_sell_value(unsigned int sell_value)
{
  _sell_value = sell_value;
}

/*
** Surcharge externes
*/

std::ostream	&game::operator<<(std::ostream &os, const Item &item)
{
  os << "Id : " << item.get_id() << std::endl
     << "Name : " << item.get_name() << std::endl
     << "Resum : " << item.get_resum() << std::endl
     << "Type : " << item.get_type() << std::endl
     << "Buy Value : " << item.get_buy_value() << std::endl
     << "Sell Value : " << item.get_sell_value() << std::endl;
  return (os);
}
