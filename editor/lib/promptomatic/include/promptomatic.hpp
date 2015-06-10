/*
** promptomatic.hpp for promptomatic in /home/laloge_h/projets/Perso/C++/MyPokemon/editor/lib/my_prompt/include
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue Jun  9 16:31:33 2015 Hugo Laloge
** Last update Wed Jun 10 10:52:18 2015 Hugo Laloge
*/

#ifndef		PROMPTOMATIC_HPP_
# define	PROMPTOMATIC_HPP_

# include	<map>
# include	<string>
# include	<utility>
# include	"arguments.hpp"
# include	"command.hpp"

typedef std::map<std::string, promptomatic::Command>	command_map;

namespace	promptomatic
{
  class		Prompt
  {
  private:
    std::string	_prompt_str;
    command_map	_command_map;
    bool	_continue;

  public:
    Prompt(const std::string &prompt_str = ">> ");
    virtual	~Prompt();

    void	set_prompt(const std::string &prompt_str);
    void	map_command(const std::string &key, command_handler_func func,
			     const std::string &helptext = "");
    void	unmap_command(const std::string &key);
    void	input_loop();
  };
}

#endif		/* !PROMPTOMATIC_HPP_ */
