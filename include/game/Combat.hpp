/*
** Combat.hpp for MyPokemon in /home/quief_h/rendu/MyPokemon
**
** Made by Hippolyte QUIEF
** Login   <quief_h@epitech.net>
**
** Started on  Tue Jun 16 11:56:41 2015 Hippolyte QUIEF
** Last update Thu Jun 18 15:47:22 2015 Hugo Laloge
*/

#ifndef		COMBAT_HPP_
# define	COMBAT_HPP_

# include	<ostream>
# include	<string>

# include	"game/Pokemon.hpp"
# include	"game/AbstractTrainer.hpp"

namespace game
{
    enum	e_weather
    {
        WEATHER_CLEAR,
        WEATHER_HOT,
        WEATHER_RAINING
    };

    enum	e_play
    {
        OWN_PLAY,
        OTHER_PLAY
    };

    class		Combat
    {
    protected:
      unsigned int	_nb_turn;
      e_weather		_weather;
      e_play		_play;
      AbstractTrainer	*_trainers[2];

    public:
      Combat(AbstractTrainer *trainer1, AbstractTrainer *trainer2);
      virtual ~Combat();

      e_play		start();

      /* Accesseurs */
      unsigned int	get_nb_turn() const;
      e_weather		get_weather() const;
      e_play		get_play() const;

        /* Asseteurs */
      void		set_weather(e_weather weather);
      void		set_play(e_play play);
    };
}

std::ostream	&operator<<(std::ostream &os, const game::Combat &fight);
unsigned int	xp_gain(game::Pokemon &poke, game::Pokemon &poke_adv);

#endif		/* !COMBAT_HPP_ */
