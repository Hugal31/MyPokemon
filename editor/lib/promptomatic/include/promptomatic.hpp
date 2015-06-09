/*
** promptomatic.hpp for promptomatic in /home/laloge_h/projets/Perso/C++/MyPokemon/editor/lib/my_prompt/include
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue Jun  9 16:31:33 2015 Hugo Laloge
** Last update Tue Jun  9 19:26:06 2015 Hugo Laloge
*/

#ifndef		PROMPTOMATIC_HPP_
# define	PROMPTOMATIC_HPP_

# include	<map>
# include	<string>
# include	<utility>
# include	"arguments.hpp"

typedef	int	(*command_handler_func)(const promptomatic::Arguments &args);
typedef std::map<std::string, std::pair<command_handler_func, std::string> >	command_map;

namespace	promptomatic
{
  class		Prompt
  {
  private:
    std::string	_prompt_str;
    command_map	_command_map;

  public:
    Prompt(const std::string &prompt_str = ">> ");
    virtual	~Prompt();

    void	set_prompt(const std::string &prompt_str);
    void	map_commande(const std::string &key, command_handler_func,
			     const std::string &helptext = "");
  };
}

#endif		/* !PROMPTOMATIC_HPP_ */
