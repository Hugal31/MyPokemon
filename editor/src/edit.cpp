/*
** set.hpp for editor in /home/laloge_h/rendu/MyPokemon/editor/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Thu Jun 11 18:28:01 2015 Hugo Laloge
** Last update Thu Jun 11 18:37:04 2015 Hugo Laloge
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
    }
  return (ret);
}
