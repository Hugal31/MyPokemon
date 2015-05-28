/*
** Editor.cpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Wed May 27 23:29:23 2015 Hugo Laloge
** Last update Thu May 28 07:50:04 2015 Hugo Laloge
*/

#include	<iostream>
#include	<s11n.net/readline/Readline.hpp>

#include	"editor/Editor.hpp"
#include	"game/PokemonModele.hpp"

using namespace	std;
using namespace	editor;

Editor::Editor()
{
  bool			continu(true);
  bool			trapped(false);
  readlinecpp::Readline	prompt;

  cout << "Mode d'edition" << endl;
  while (continu && !trapped)
    {
      string line = prompt.readline("editor> ", trapped);
    }
  cout << endl;
}
