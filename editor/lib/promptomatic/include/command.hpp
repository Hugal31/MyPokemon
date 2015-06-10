/*
** command.hpp for promptomatic in /home/laloge_h/rendu/MyPokemon/editor/lib/promptomatic/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Wed Jun 10 10:15:00 2015 Hugo Laloge
** Last update Wed Jun 10 10:25:40 2015 Hugo Laloge
*/

#ifndef		PROMPTOMATIC_COMMAND_HPP_
# define	PROMPTOMATIC_COMMAND_HPP_

# include	"arguments.hpp"

typedef	int	(*command_handler_func)(const promptomatic::Arguments &args);

namespace	promptomatic
{
  struct	Command
  {
    command_handler_func	func;
    std::string			desc;

    Command(command_handler_func param_func, const std::string &param_desc = "");
    virtual	~Command();
  };
}

#endif		/* !PROMPTOMATIC_COMMAND_HPP_ */
