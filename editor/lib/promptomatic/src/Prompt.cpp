/*
** init.cpp for promptomatic in /home/laloge_h/projets/Perso/C++/MyPokemon/editor/lib/my_prompt/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue Jun  9 16:12:38 2015 Hugo Laloge
** Last update Wed Jun 10 17:55:58 2015 Hugo Laloge
*/

#include	<iostream>
#include	<string>
#include	<utility>
#include	"promptomatic.hpp"

promptomatic::Prompt::Prompt(const std::string &prompt_str) :
  _prompt_str(prompt_str), _continue(true)
{
  _intern_command_map.insert(std::pair<std::string, promptomatic::InternCommand>("exit", promptomatic::InternCommand(prompt_exit, "exit the prompt")));
  _intern_command_map.insert(std::pair<std::string, promptomatic::InternCommand>("help", promptomatic::InternCommand(prompt_help, "display help")));
}

promptomatic::Prompt::~Prompt()
{

}

promptomatic::command_map	&promptomatic::Prompt::get_command_map()
{
  return (_command_map);
}

promptomatic::intern_command_map	&promptomatic::Prompt::get_intern_command_map()
{
  return (_intern_command_map);
}

void	promptomatic::Prompt::set_prompt(const std::string &prompt_str)
{
  _prompt_str = prompt_str;
}

void	promptomatic::Prompt::map_command(const std::string &key,
					  cmd_handler_func func,
					  const std::string &helptext)
{
  _command_map.insert(std::pair<std::string, promptomatic::Command>(key, promptomatic::Command(func, helptext)));
}

void	promptomatic::Prompt::unmap_command(const std::string &key)
{
  _command_map.erase(key);
  _intern_command_map.erase(key);
}

void	promptomatic::Prompt::input_loop()
{
  std::string		line;
  command_map::iterator	cmd;
  intern_command_map::iterator	intern_cmd;

  std::cout << _prompt_str;
  while (_continue && std::getline(std::cin, line))
    {
      promptomatic::Arguments	args(line);
      if (args.argc() >= 1)
	{
	  if ((cmd = _command_map.find(args[0])) != _command_map.end())
	    cmd->second.func(args);
	  else if ((intern_cmd = _intern_command_map.find(args[0])) != _intern_command_map.end())
	    intern_cmd->second.func(args, *this);
	}
      std::cout << _prompt_str;
    }
  std::cout << "exit" << std::endl;
}

void	promptomatic::Prompt::stop_loop()
{
  _continue = false;
}
