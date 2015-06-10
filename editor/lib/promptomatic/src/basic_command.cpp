/*
** basic_command.cpp for promptomatic in /home/laloge_h/rendu/MyPokemon/editor/lib/promptomatic/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Wed Jun 10 10:53:07 2015 Hugo Laloge
** Last update Wed Jun 10 17:54:45 2015 Hugo Laloge
*/

#include	<iostream>
#include	"promptomatic.hpp"

int	promptomatic::prompt_exit(const Arguments &args, Prompt &prompt)
{
  (void)args;
  prompt.stop_loop();
  return (0);
}

int	promptomatic::prompt_help(const Arguments &args, Prompt &prompt)
{
  (void)args;
  for (intern_command_map::iterator it(prompt.get_intern_command_map().begin());
       it != prompt.get_intern_command_map().end();
       it++)
    {
      std::cout << it->first;
      if (it->second.desc != "")
	std::cout << " : " << it->second.desc;
      std::cout << std::endl;
    }
  for (command_map::iterator it(prompt.get_command_map().begin());
       it != prompt.get_command_map().end();
       it++)
    {
      std::cout << it->first;
      if (it->second.desc != "")
	std::cout << " : " << it->second.desc;
      std::cout << std::endl;
    }
  return (0);
}
