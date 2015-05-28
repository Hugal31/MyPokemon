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
# include	<boost/program_options/options_description.hpp>
# include	<boost/program_options/variables_map.hpp>
# include	<boost/program_options/parsers.hpp>
#pragma clang diagnostic pop

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
