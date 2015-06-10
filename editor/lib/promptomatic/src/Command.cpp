/*
** Command.cpp for promptomatic in /home/laloge_h/rendu/MyPokemon/editor/lib/promptomatic/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Wed Jun 10 10:20:36 2015 Hugo Laloge
** Last update Wed Jun 10 10:51:11 2015 Hugo Laloge
*/

#include	"command.hpp"

promptomatic::Command::Command(command_handler_func param_func,
			       const std::string &param_desc) :
  func(param_func),  desc(param_desc)
{

}

promptomatic::Command::~Command()
{

}
