/*
** Arguments.cpp for promptomatic in /home/laloge_h/projets/Perso/C++/MyPokemon/editor/lib/promptomatic/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue Jun  9 17:02:55 2015 Hugo Laloge
** Last update Wed Jun 10 10:11:36 2015 Hugo Laloge
*/

#include	<deque>
#include	<cstddef>
#include	<sstream>
#include	<string>
#include	"arguments.hpp"

promptomatic::Arguments::Arguments(const std::string args)
{
  std::stringstream	ss(args);
  std::string		word;

  while (ss >> word)
    {
      _args_list.push_back(word);
    }
}

size_t	promptomatic::Arguments::argc() const
{
  return (_args_list.size());
}

const args_list	&promptomatic::Arguments::argv() const
{
  return (_args_list);
}

args_list	&promptomatic::Arguments::argv()
{
  return (_args_list);
}

std::string	promptomatic::Arguments::shift()
{
  std::string	front(_args_list[0]);

  _args_list.pop_front();
  return (front);
}

void	promptomatic::Arguments::push_front(const std::string &arg)
{
  _args_list.push_front(arg);
}

void	promptomatic::Arguments::push_back(const std::string &arg)
{
  _args_list.push_back(arg);
}

#if __cplusplus > 199711L
args_const_iterator	promptomatic::Arguments::begin() const
{
  return (_args_list.cbegin());
}

args_const_iterator	promptomatic::Arguments::end() const
{
  return (_args_list.end());
}
#endif

args_iterator		promptomatic::Arguments::begin()
{
  return (_args_list.begin());
}

args_iterator		promptomatic::Arguments::end()
{
  return (_args_list.end());
}


const std::string &promptomatic::Arguments::operator[](size_t index) const
{
  return (_args_list[index]);
}
