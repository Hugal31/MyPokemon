/*
** Editor.cpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Wed May 27 23:29:23 2015 Hugo Laloge
** Last update Thu May 28 08:49:32 2015 Hugo Laloge
*/

#include	<iostream>
#include	<s11n.net/readline/Readline.hpp>
#include	<s11n.net/shellish/shellish.hpp>

#include	"editor/Editor.hpp"
#include	"game/PokemonModele.hpp"

using namespace	std;
using namespace	editor;

namespace
{
  int	test_handler(const shellish::arguments &args)
  {
    cout << "Test reussi !" << endl;
    return (0);
  }
}

Editor::Editor()
{
  bool			continu(true);
  bool			trapped(false);
  readlinecpp::Readline	line_editor;

  shellish::init(0, NULL);
  shellish::map_commander("test", &test_handler);
  cout << "Mode d'edition" << endl;
  shellish::input_loop("prompt> ");
  cout << endl;
}
