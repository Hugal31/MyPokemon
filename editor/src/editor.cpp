/*
** Editor.cpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Wed May 27 23:29:23 2015 Hugo Laloge
** Last update Tue Jun  9 15:40:50 2015 Hippolyte QUIEF
*/

#include	<string>
#include	<fstream>
#include	<iostream>

#include	"editor.hpp"
#include	"game/PokemonModele.hpp"

using namespace	std;
using namespace	editor;

namespace	ba = boost::archive;

namespace
{
  game::PokemonModele	*target(NULL);

  int new_pokemon_modele_from_id(unsigned int id)
  {
    if (target != NULL)
      delete target;
    target = new game::PokemonModele(id);
    return (0);
  }

  // handlers pour shellist

  int	create_poke_handler(const shellish::arguments &args)
  {
    if (args.argc() != 2)
      cerr << "usage :" << endl << "create id" << endl;
    else
      {
	unsigned int	id;

	try {
	  id = static_cast<unsigned int>(stoi(args[1]));
	  new_pokemon_modele_from_id(id);
	  cout << *target;
	} catch (invalid_argument) {
	  cerr << "invalid argument" << endl;
	}
      }
    return (0);
  }

  int	open_poke_handler(const shellish::arguments &args)
  {
    if (args.argc() != 2)
      cerr << "usage :" << endl << "open <id>" << endl;
    else
      {
	try {
	  size_t		idx;
	  unsigned int		id(static_cast<unsigned int>(stoi(args[1], &idx)));
	  if (args[1].c_str()[idx] != '\0')
	    throw (invalid_argument("stoi"));
	  ifstream		file(args[1] + ".poke");

	  new_pokemon_modele_from_id(id);
	  ba::text_iarchive	ia(file);
	  ia >> *target;
	} catch (invalid_argument) {
	  cerr << "invalid argument" << endl;
	}
      }
    return (0);
  }

  int	set_handler(const shellish::arguments &args)
  {
    int	ret(-1);

    if (args.argc() != 3)
      cerr << "usage :" << endl << "set <attribut> <value>" << endl;
    else if (target == NULL)
      cerr << "you need to create or open a pokemon first" << endl;
    else
      {
	ret = 0;
	if (args[1] == "name")
	  target->set_name(args[2]);
	else if (args[1] == "species")
	  target->set_species(args[2]);
	else if (args[1] == "resum")
	  target->set_resum(args[2]);
      }
    return (0);
  }

  int	view_handler(const shellish::arguments &args)
  {
    int	ret(-1);

    (void)args;
    if (target == NULL)
      cerr << "no pokemon selected" << endl;
    else
      {
	cout << *target;
	ret = 0;
      }
    return (0);
  }

  int	save_handler(const shellish::arguments &args)
  {
    int	ret(-1);

    if (args.argc() != 1)
      cerr << "save doesn't need argument" << endl;
    else if (target == NULL)
      cerr << "no pokemon selected" << endl;
    else
      {
	ofstream		file(to_string(target->get_id()) + ".poke");

	ba::text_oarchive	oa(file);
	oa << *target;
	ret = 0;
      }
    return (ret);
  }
}

int	editor::editor(void)
{
  /*shellish::init(0, NULL);
  shellish::map_commander("create", &create_poke_handler, "create a pokemon");
  shellish::map_commander("open", &open_poke_handler, "ouvre le fichier d'un pokemon");
  shellish::map_commander("set", &set_handler, "set pokemon attributs");
  shellish::map_commander("view", &view_handler, "view pokemon attributs");
  shellish::map_commander("save", &save_handler, "save pokemon");
  cout << "Mode d'edition" << endl;
  shellish::input_loop(">>  ");
  cout << endl;*/
  return (0);
}
