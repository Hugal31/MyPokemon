/*
** AbstractTrainer.hpp for MyPokemon in /home/laloge_h/rendu/MyPokemon/src/game/Player
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Thu Jun 18 13:45:25 2015 Hugo Laloge
** Last update Thu Jun 18 15:43:57 2015 Hugo Laloge
*/

#ifndef		ABSTRACTTRAINER_HPP_
# define	ABSTRACTTRAINER_HPP_

namespace game
{
  class		AbstractTrainer
  {
  protected:

  public:
    virtual		~AbstractTrainer();
    virtual bool	lose() = 0;
  };
}

#endif		/* !ABSTRACTTRAINER_HPP_ */
