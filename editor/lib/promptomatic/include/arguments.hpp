/*
** arguments.hpp for promptomatic in /home/laloge_h/projets/Perso/C++/MyPokemon/editor/lib/promptomatic/src
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Tue Jun  9 16:52:27 2015 Hugo Laloge
** Last update Wed Jun 10 10:10:48 2015 Hugo Laloge
*/

#ifndef		PROMPTOMATIC_ARGUMENTS_HPP_
# define	PROMPTOMATIC_ARGUMENTS_HPP_

# include	<deque>
# include	<cstddef>
# include	<string>

typedef	std::deque<std::string>	args_list;
typedef args_list::iterator	args_iterator;
typedef args_list::const_iterator	args_const_iterator;

namespace	promptomatic
{
  class		Arguments
  {
  private:
    args_list	_args_list;

  public:
    Arguments(const std::string args);

    size_t		argc() const;
    const args_list	&argv() const;
    args_list		&argv();
    std::string		shift();

    void		push_front(const std::string &arg);
    void		push_back(const std::string &arg);

    /* iterators */
# if __cplusplus > 199711L
    args_const_iterator	begin() const;
    args_const_iterator	end() const;
# endif	/* __cplusplus > 199711L */
    args_iterator	begin();
    args_iterator	end();

    const std::string	&operator[](size_t index) const;
  };
}

#endif		/* !PROMPTOMATIC_ARGUMENTS_HPP_ */
