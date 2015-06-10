/*
** promptomatic.hpp for promptomatic in /home/laloge_h/projets/Perso/C++/MyPokemon/editor/lib/my_prompt/include
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue Jun  9 16:31:33 2015 Hugo Laloge
** Last update Wed Jun 10 17:46:08 2015 Hugo Laloge
*/

#ifndef		PROMPTOMATIC_HPP_
# define	PROMPTOMATIC_HPP_

# include	<map>
# include	<string>
# include	<utility>

# include	"arguments.hpp"
# include	"command.hpp"

namespace	promptomatic
{

  typedef std::map<std::string, Command>	command_map;
  typedef std::map<std::string, InternCommand>	intern_command_map;

  class		Prompt
  {
  private:
    std::string		_prompt_str;
    command_map		_command_map;
    intern_command_map	_intern_command_map;
    bool		_continue;

  public:
    Prompt(const std::string &prompt_str = ">> ");
    virtual	~Prompt();

    command_map	&get_command_map();
    intern_command_map	&get_intern_command_map();

    void	set_prompt(const std::string &prompt_str);
    void	map_command(const std::string &key, cmd_handler_func func,
			     const std::string &helptext = "");
    void	unmap_command(const std::string &key);
    void	input_loop();
    void	stop_loop();
  };

  int	prompt_exit(const Arguments &args, Prompt &prompt);
  int	prompt_help(const Arguments &args, Prompt &prompt);
}

#endif		/* !PROMPTOMATIC_HPP_ */
