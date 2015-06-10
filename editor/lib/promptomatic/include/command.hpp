/*
** command.hpp for promptomatic in /home/laloge_h/rendu/MyPokemon/editor/lib/promptomatic/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Wed Jun 10 10:15:00 2015 Hugo Laloge
** Last update Wed Jun 10 17:24:19 2015 Hugo Laloge
*/

#ifndef		PROMPTOMATIC_COMMAND_HPP_
# define	PROMPTOMATIC_COMMAND_HPP_

# include	"arguments.hpp"

namespace	promptomatic
{
  class	Prompt;

  typedef int	(*cmd_handler_func)(const Arguments &args);
  typedef int	(*intern_cmd_handler_func)(const Arguments &args, Prompt &prompt);

  struct	Command
  {
    cmd_handler_func	func;
    std::string		desc;

    Command(cmd_handler_func param_func, const std::string &param_desc = "");
    virtual	~Command();
  };

  struct	InternCommand
  {
    intern_cmd_handler_func	func;
    std::string			desc;

    InternCommand(intern_cmd_handler_func param_func, const std::string &param_desc = "");
    virtual	~InternCommand();
  };
}

#endif		/* !PROMPTOMATIC_COMMAND_HPP_ */
