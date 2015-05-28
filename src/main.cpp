/*
** main.cpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue May 26 15:55:50 2015 Hugo Laloge
** Last update Wed May 27 23:26:02 2015 Hugo Laloge
*/

#include	<exception>
#include	<iostream>
#include	<cstdlib>
#include	"editor/Editor.hpp"
#include	"game/PokemonModele.hpp"

#pragma GCC push
#pragma GCC system_header
# include	<boost/program_options/options_description.hpp>
# include	<boost/program_options/variables_map.hpp>
# include	<boost/program_options/parsers.hpp>
#pragma GCC pop

// Raccourcis pour les fonctionnalités du parseur d'argument de boost
namespace po = boost::program_options;

int				main(int argc, char **argv)
{
  int				ret;
  po::options_description	desc("Allowed options");
  po::variables_map		vm;

  ret = EXIT_SUCCESS;
  desc.add_options()
    ("help,h", "produce help message")
    ("editor,e", "open the pokemon editor");
  try
    {
      po::store(po::parse_command_line(argc, argv, desc), vm);
      po::notify(vm);
      if (vm.count("help"))
	std::cout << desc << std::endl;
      else if (vm.count("editor"))
	editor::Editor();
    }
  catch (const std::exception &e)
    {
      std::cerr << e.what() << std::endl;
      ret = EXIT_FAILURE;
    }
  return (ret);
}
