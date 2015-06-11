/*
** Editor.hpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon/src/game/PokemonModele
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Wed May 27 23:27:04 2015 Hugo Laloge
** Last update Thu Jun 11 18:36:06 2015 Hugo Laloge
*/

#ifndef		EDITOR_HPP_
# define	EDITOR_HPP_

# include	"promptomatic.hpp"
# include	"game/PokemonModel.hpp"

namespace	editor
{
  extern game::PokemonModel	*target;

  int	editor(void);
  int	set_handler(const promptomatic::Arguments &args);
}

#endif		/* !EDITOR_HPP_ */
