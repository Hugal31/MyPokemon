/*
** main.cpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue May 26 15:55:50 2015 Hugo Laloge
** Last update Tue May 26 16:01:15 2015 Hugo Laloge
*/

#include	<iostream>
#include	"game/PokemonModele.hpp"

int	main()
{
  for (unsigned int i(0); i < 125; i++)
    {
      std::cout << game::PokemonModele(i) << std::endl;
    }
  return (0);
}
