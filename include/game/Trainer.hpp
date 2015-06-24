/*
** Trainer.hpp
** Created by laloge_h on 18 juin 06:03 2015.
*/

#ifndef		TRAINER_HPP_
# define	TRAINER_HPP_

# include	<string>
# include	"game/AbstractTrainer.hpp"
# include	"game/Pokemon.hpp"

# define	MAX_POKEMON	6

namespace game
{
  enum		e_gender
    {
      GENDER_MALE,
      GENDER_FEMALE
    };

  class		Trainer : public AbstractTrainer
  {
  protected:
    e_gender				_gender;
    std::string				_name;
    std::array<Pokemon*, MAX_POKEMON>	_pokemons;
    Pokemon				*_current_pokemon;

  public:
    Trainer(const std::string &name, e_gender gender = GENDER_MALE);
    virtual	~Trainer();

    virtual void	set_current_pokemon(unsigned int index);

    bool	lose();
    Pokemon	*get_current_pokemon();
  };
}

#endif		/* !TRAINER_H_ */
