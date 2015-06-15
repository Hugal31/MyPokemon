/*
** no_warnings.hpp for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
**
** Made by Hugo Laloge
** Login   <laloge_h@epitech.net>
**
** Started on  Wed Jun  3 13:04:54 2015 Hugo Laloge
** Last update Mon Jun 15 13:34:42 2015 Hugo Laloge
*/

#ifndef		NO_WARNINGS_H_
# define	NO_WARNINGS_H_

# ifdef	__clang__
#  define       NO_WARNINGS						\
  _Pragma("clang diagnostic push")					\
  _Pragma("clang diagnostic ignored \"-Wweak-vtables\"")		\
  _Pragma("clang diagnostic ignored \"-Wextra-semi\"")			\
  _Pragma("clang diagnostic ignored \"-Wconversion\"")			\
  _Pragma("clang diagnostic ignored \"-Wunused-parameter\"")		\
  _Pragma("clang diagnostic ignored \"-Wundef\"")			\
  _Pragma("clang diagnostic ignored \"-Wc++98-compat-pedantic\"")	\
  _Pragma("clang diagnostic ignored \"-Wdeprecated\"")			\
  _Pragma("clang diagnostic ignored \"-Wglobal-constructors\"")		\
  _Pragma("clang diagnostic ignored \"-Wexit-time-destructors\"")	\
  _Pragma("clang diagnostic ignored \"-Wdivision-by-zero\"")		\
  _Pragma("clang diagnostic ignored \"-Wunused-local-typedef\"")	\
  _Pragma("clang diagnostic ignored \"-Wold-style-cast\"")		\
  _Pragma("clang diagnostic ignored \"-Wreserved-id-macro\"")		\
  _Pragma("clang diagnostic ignored \"-Winconsistent-missing-override\"")
#  define	WARNINGS	_Pragma("clang diagnostic pop")
# else
#  define       NO_WARNINGS
#  define	WARNINGS
# endif


#endif		/* !NO_WARNINGS_H_ */
