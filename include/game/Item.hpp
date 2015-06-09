/*
** Item.hpp for MyPokemon in /home/quief_h/rendu/MyPokemon/include/game
**
** Made by Hippolyte QUIEF
** Login   <quief_h@epitech.net>
**
** Started on  Thu Jun  4 09:42:29 2015 Hippolyte QUIEF
** Last update Tue Jun  9 16:01:02 2015 Hugo Laloge
*/

#ifndef		ITEM_H_
# define	ITEM_H_

# include	<string>

# include	"no_warnings.hpp"

NO_WARNINGS

# include	<boost/archive/text_oarchive.hpp>
# include	<boost/archive/text_iarchive.hpp>

WARNINGS

namespace	game
{
  enum		e_item_type
    {
      ITEM_TYPE_ITEMS,
      ITEM_TYPE_MED,
      ITEM_TYPE_POKEBALL,
      ITEM_TYPE_TM_HM,
      ITEM_TYPE_BERRIES,
      ITEM_TYPE_BATTLE,
      ITEM_TYPE_KEY
    };

  class			Item
  {
  protected:
    std::string		_name;
    std::string		_resum;
    unsigned int	_id;
    e_item_type		_type;
    unsigned int	_buy_value;
    unsigned int	_sell_value;

    /* Serialisation */

    template<class Archive>
    void		serialize(Archive &ar, const unsigned int version)
    {
      (void)version;
      ar & _name;
      ar & _resum;
      ar & _id;
      ar & _type;
      ar & _buy_value;
      ar & _sell_value;
    }

  public:
    /* Constructeur */
    Item(unsigned int id);
    virtual		~Item();

    /* Accesseurs */
    const std::string	&get_name() const;
    const std::string	&get_resum() const;
    unsigned int	get_id() const;
    e_item_type		get_type() const;
    unsigned int	get_buy_value() const;
    unsigned int	get_sell_value() const;

    /* Assesseurs */
    void		set_name(const std::string &name);
    void		set_resum(const std::string &resum);
    void		set_type(e_item_type type);
    void		set_buy_value(unsigned int buy_value);
    void		set_sell_value(unsigned int sell_value);
  };

  std::ostream &operator<<(std::ostream &os, const Item &item);
}

NO_WARNINGS
BOOST_CLASS_VERSION(game::Item, 0)
WARNINGS

#endif		/* !ITEM_H_ */
