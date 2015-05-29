/*
** Editor.cpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Wed May 27 23:29:23 2015 Hugo Laloge
** Last update Fri May 29 17:25:29 2015 Hugo Laloge
*/

#include	<string>
#include	<fstream>
#include	<iostream>
#include	<s11n.net/readline/Readline.hpp>
#include	<s11n.net/shellish/shellish.hpp>

#include	"editor.hpp"
#include	"game/PokemonModele.hpp"

using namespace	std;
using namespace	editor;

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
      cerr << "usage :" << endl << "new id" << endl;
    else
      {
	unsigned int	id;

	id = (unsigned int)stoi(args[1]);
	new_pokemon_modele_from_id(id);
	cout << *target;
      }
    return (0);
  }

  int	open_poke_handler(const shellish::arguments &args)
  {
    (void)args;
    new_pokemon_modele_from_id(0);
    {
      ifstream	file("file.poke");

      boost::archive::text_iarchive	ia(file);
      ia >> *target;
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
      }
    return (0);
  }

  int	view_handler(const shellish::arguments &args)
  {
    int	ret(-1);

    (void)args;
    if (target == NULL)
      cerr << "No pokemon selected" << endl;
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

    (void)args;
    if (target == NULL)
      ;
    else
      {
	ofstream	file("file.poke");

	boost::archive::text_oarchive	oa(file);
	oa << *target;
	ret = 0;
      }
    return (ret);
  }

}

int	editor::editor(void)
{
  readlinecpp::Readline	line_editor;

  shellish::init(0, NULL);
  shellish::map_commander("create", &create_poke_handler, "create a pokemon");
  shellish::map_commander("open", &open_poke_handler, "ouvre le fichier d'un pokemon");
  shellish::map_commander("set", &set_handler, "set pokemon attributs");
  shellish::map_commander("view", &view_handler, "view pokemon attributs");
  shellish::map_commander("save", &save_handler, "save pokemon");
  cout << "Mode d'edition" << endl;
  shellish::input_loop(">> ");
  cout << endl;
  return (0);
}
