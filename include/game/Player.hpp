/*
** Player.hpp
** Created by laloge_h on 18 juin 06:00 2015.
*/

#ifndef		PLAYER_HPP_
# define	PLAYER_HPP_

# include	<array>
# include	"game/Trainer.hpp"
# include	"game/id.hpp"

namespace game
{
  class		Player : public Trainer
  {
  protected:
    Id		_id;
    Id		_secret_id;
    //unsigned int		_money;

  public:
    Player(const std::string &name, e_gender gender = GENDER_MALE);
    virtual	~Player();

    void	set_pokemon(Pokemon *pokemon, unsigned int index);

    void	play(Combat *fight, AbstractTrainer *opponent);
  };
}

#endif		/* !PLAYER_HPP_ */
