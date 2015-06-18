/*
** WildTrainer.hpp for MyPokemon in /home/laloge_h/rendu/MyPokemon/src/game/Player
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Thu Jun 18 13:48:41 2015 Hugo Laloge
** Last update Thu Jun 18 14:18:05 2015 Hugo Laloge
*/

#ifndef		WILDTRAINER_H_
# define	WILDTRAINER_H_

# include	"game/AbstractTrainer.hpp"
# include	"game/id.hpp"
# include	"game/PokemonModel.hpp"
# include	"game/Pokemon.hpp"

namespace game
{
  class		WildTrainer : public AbstractTrainer
  {
  protected:
    Pokemon	*_pokemon;

  public:
    WildTrainer(Id id, unsigned int level);
    WildTrainer(Pokemon *poke);
    virtual	~WildTrainer();
  };
}

#endif		/* !WILDTRAINER_H_ */
