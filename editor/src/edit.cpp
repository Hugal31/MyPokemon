/*
** set.hpp for editor in /home/laloge_h/rendu/MyPokemon/editor/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Thu Jun 11 18:28:01 2015 Hugo Laloge
** Last update Thu Jun 11 18:57:09 2015 Hugo Laloge
*/
#include	<string>
#include	<iostream>
#include	"promptomatic.hpp"

#include	"editor.hpp"
#include	"game/PokemonModel.hpp"

using namespace	std;
using namespace	editor;
namespace	pt = promptomatic;

namespace
{
  int	set_types(const pt::Arguments &args)
  {
    target->set_types(args[2], (args.argc() > 3) ? args[3] : "NONE");
    return (0);
  }

  int	set_max_xp(const pt::Arguments &args)
  {
    int	ret(-1);

    try {
      unsigned int max_xp(static_cast<unsigned int>(stoi(args[2])));
      target->set_max_xp(max_xp);
      ret = 0;
    }
    catch (invalid_argument) {
      cerr << "invalid argument" << endl;
    }
    return (ret);
  }

  int	set_heigth_weight(const pt::Arguments &args)
  {
    int	ret(-1);

    try {
      unsigned short int value(static_cast<unsigned short int>(stoi(args[2])));
      if (args[1] == "heigth")
	target->set_heigth(value);
      else
	target->set_weight(value);
    }
    catch (invalid_argument) {
      cerr << "invalid argument" << endl;
    }
    return (ret);
  }

  int	set_rate(const pt::Arguments &args)
  {
    int	ret(-1);

    try {
      unsigned short int value(static_cast<unsigned short int>(stoi(args[2])));
      if (value > 100)
	throw invalid_argument("Rate too big");
      if (args[1] == "catch_rate")
	target->set_catch_rate(value);
      else
	target->set_gender_rate(value);
    }
    catch (const invalid_argument &e) {
      cerr << "invalid argument : " << e.what() << endl;
    }
    return (ret);
  }
}

int	editor::set_handler(const pt::Arguments &args)
{
  int	ret(-1);

  if (args.argc() < 3)
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
      else if (args[1] == "types")
        ret = set_types(args);
      else if (args[1] == "max_xp")
	ret = set_max_xp(args);
      else if (args[1] == "heigth" or args[1] == "weight")
	ret = set_heigth_weight(args);
      else if (args[1] == "catch_rate" or args[1] == "catch_rate")
	ret = set_rate(args);
    }
  return (ret);
}
