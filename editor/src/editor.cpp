/*
** Editor.cpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Wed May 27 23:29:23 2015 Hugo Laloge
** Last update Thu Jun 11 18:27:57 2015 Hugo Laloge
*/

#include	<string>
#include	<fstream>
#include	<iostream>
#include	"promptomatic.hpp"

#include	"editor.hpp"
#include	"game/PokemonModel.hpp"

using namespace	std;
using namespace	editor;

namespace	pt = promptomatic;
namespace	ba = boost::archive;

game::PokemonModel	*editor::target(NULL);

namespace
{
  std::string	get_file_name(const std::string &id_str)
  {
    size_t		idx;
    unsigned int	id(static_cast<unsigned int>(stoi(id_str, &idx)));

    if (idx != id_str.size())
      throw (invalid_argument("stoi"));
    return ("../ressources/pokemon/" + to_string(id) + ".poke");
  }

  std::string	get_file_name(unsigned int id)
  {
    return ("../ressources/pokemon/" + to_string(id) + ".poke");
  }

  int new_pokemon_model(unsigned int id = 0)
  {
    if (target != NULL)
      delete target;
    target = new game::PokemonModel(id);
    return (0);
  }

  // handlers pour promptomatic

  int	create_poke_handler(const pt::Arguments &args)
  {
    if (args.argc() != 2)
      cerr << "usage :" << endl << "create id" << endl;
    else
      {
	unsigned int	id;

	try {
	  id = static_cast<unsigned int>(stoi(args[1]));
	  if (id == 0)
	    throw invalid_argument("inferieur a 1");
	  new_pokemon_model(id);
	  cout << *target;
	} catch (invalid_argument) {
	  cerr << "invalid argument" << endl;
	}
      }
    return (0);
  }

  int	open_poke_handler(const pt::Arguments &args)
  {
    if (args.argc() != 2)
      cerr << "usage :" << endl << "open <id>" << endl;
    else
      {
	try {
	  ifstream	file(get_file_name(args[1]));
	  if (file)
	    {
	      new_pokemon_model();
	      ba::text_iarchive	ia(file);
	      ia >> *target;
	    }
	  else
	    cerr << "invalid file" << endl;
	} catch (invalid_argument) {
	  cerr << "invalid argument" << endl;
	}
      }
    return (0);
  }

  int	view_handler(const pt::Arguments &args)
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

  int	save_handler(const pt::Arguments &args)
  {
    int	ret(-1);

    if (args.argc() != 1)
      cerr << "save doesn't need argument" << endl;
    else if (target == NULL)
      cerr << "no pokemon selected" << endl;
    else
      {
	ofstream		file(get_file_name(target->get_id()));

	if (file)
	  {
	    ba::text_oarchive	oa(file);
	    oa << *target;
	    ret = 0;
	  }
	else
	  cerr << "invalid file" << endl;
      }
    return (ret);
  }
}

int	editor::editor(void)
{
  pt::Prompt	prompt;

  prompt.map_command("create", &create_poke_handler, "create a pokemon");
  prompt.map_command("open", &open_poke_handler, "open a pokemon file");
  prompt.map_command("set", &set_handler, "set pokemon attributs");
  prompt.map_command("view", &view_handler, "view pokemon attributs");
  prompt.map_command("save", &save_handler, "save pokemon");
  cout << "Mode d'edition" << endl;
  prompt.input_loop();
  return (0);
}
