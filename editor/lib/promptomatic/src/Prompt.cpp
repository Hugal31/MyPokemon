/*
** init.cpp for promptomatic in /home/laloge_h/projets/Perso/C++/MyPokemon/editor/lib/my_prompt/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue Jun  9 16:12:38 2015 Hugo Laloge
** Last update Tue Jun  9 19:27:48 2015 Hugo Laloge
*/

#include	<string>
#include	<utility>
#include	"promptomatic.hpp"

promptomatic::Prompt::Prompt(const std::string &prompt_str) :
  _prompt_str(prompt_str)
{

}

void	promptomatic::Prompt::set_prompt(const std::string &prompt_str)
{
  _prompt_str = prompt_str;
}

void	promptomatic::Prompt::map_commande(const std::string &key,
					   command_handler_func func,
					   const std::string &helptext)
{
  _command_map.insert(std::pair<std::string, std::pair<command_handler_func, std::string> >(key, std::pair<command_handler_func, std::string>(func, helptext)));
}
