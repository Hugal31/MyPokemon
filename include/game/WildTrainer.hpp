/*
** WildTrainer.hpp
** Created by laloge_h on 18 juin 06:03 2015.
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

    /* Attention : delete le pokemon */
    WildTrainer(Pokemon *poke);
    virtual	~WildTrainer();

    bool	lose();
    Pokemon	*get_current_pokemon();
    void	play(Combat *fight, AbstractTrainer *opponent);
  };
}

#endif		/* !WILDTRAINER_H_ */
