/*
** AbstractTrainer.hpp
** Created by laloge_h on 18 juin 05:59 2015.
*/

#ifndef		ABSTRACTTRAINER_HPP_
# define	ABSTRACTTRAINER_HPP_

#include <game/Pokemon.hpp>

namespace game
{
  class		AbstractTrainer
  {
  protected:

  public:
    virtual		~AbstractTrainer();

    virtual bool	lose() = 0;
    virtual Pokemon	*get_current_pokemon() = 0;
  };
}

#endif		/* !ABSTRACTTRAINER_HPP_ */
