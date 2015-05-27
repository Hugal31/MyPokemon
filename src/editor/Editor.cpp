/*
** Editor.cpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Wed May 27 23:29:23 2015 Hugo Laloge
** Last update Wed May 27 23:58:51 2015 Hugo Laloge
*/

#include	<iostream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wweak-vtables"
#pragma clang diagnostic ignored "-Wextra-semi"
#pragma clang diagnostic ignored "-Wconversion"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wundef"
#pragma clang diagnostic ignored "-Wswitch-enum"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wdeprecated"
#pragma clang diagnostic ignored "-Wdisabled-macro-expansion"
#pragma clang diagnostic ignored "-Wdocumentation"
# include	<boost/program_options.hpp>
#pragma clang diagnostic pop

#include	"editor/Editor.hpp"
#include	"game/PokemonModele.hpp"

using namespace	std;
using namespace	editor;

namespace po = boost::program_options;

Editor::Editor()
{
  bool				continu(true);

  cout << "Mode d'edition" << endl;
  while (continu && !cin.fail())
    {
      continu = false;
    }
}
