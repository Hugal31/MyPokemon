/*
** init.cpp for promptomatic in /home/laloge_h/projets/Perso/C++/MyPokemon/editor/lib/my_prompt/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue Jun  9 16:12:38 2015 Hugo Laloge
** Last update Wed Jun 10 10:52:50 2015 Hugo Laloge
*/

#include	<iostream>
#include	<string>
#include	<utility>
#include	"promptomatic.hpp"

promptomatic::Prompt::Prompt(const std::string &prompt_str) :
  _prompt_str(prompt_str), _continue(true)
{

}

promptomatic::Prompt::~Prompt()
{

}

void	promptomatic::Prompt::set_prompt(const std::string &prompt_str)
{
  _prompt_str = prompt_str;
}

void	promptomatic::Prompt::map_command(const std::string &key,
					  command_handler_func func,
					  const std::string &helptext)
{
  _command_map.insert(std::pair<std::string, promptomatic::Command>(key, promptomatic::Command(func, helptext)));
}

void	promptomatic::Prompt::unmap_command(const std::string &key)
{
  _command_map.erase(key);
}

void	promptomatic::Prompt::input_loop()
{
  std::string		line;
  command_map::iterator	cmd;

  std::cout << _prompt_str;
  while (_continue && std::getline(std::cin, line))
    {
      promptomatic::Arguments	args(line);
      if ((cmd = _command_map.find(args[0])) != _command_map.end())
	cmd->second.func(args);
      std::cout << _prompt_str;
    }
  std::cout << std::endl;
}
