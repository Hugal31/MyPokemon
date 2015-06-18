/*
** Trainer.hpp for MyPokemon in /home/laloge_h/rendu/MyPokemon/src/game/Player
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Thu Jun 18 13:36:19 2015 Hugo Laloge
** Last update Thu Jun 18 14:15:38 2015 Hugo Laloge
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

  public:
    Trainer(const std::string &name, e_gender gender = GENDER_MALE);
    virtual	~Trainer();
  };
}

#endif		/* !TRAINER_H_ */
