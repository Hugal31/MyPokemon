##
## Makefile for promptomatic in /home/laloge_h/projets/Perso/C++/MyPokemon/editor/lib/my_shellish
##
## Made by Hugo Laloge
## Login   <laloge_h@epitech.net>
##
## Started on  Tue Jun  9 16:11:10 2015 Hugo Laloge
## Last update Wed Jun 10 17:02:27 2015 Hugo Laloge
##

NAME	=	libpromptomatic.a

include	sources.mk

OBJS	=	$(SRCS:.cpp=.o)

DEPS	=	$(SRCS:.cpp=.depend)

INCLUDE	=	-I include						\

RM	=	rm -f

CXXFLAGS+=	$(INCLUDE)

CLANG	?=	0

DEBUG	?=	0

WERROR	?=	0

ifeq ($(CLANG), 1)
	CXX	=	clang++
	CXXFLAGS+=	-Weverything -Wno-padded			\

else
	CXX	=	g++
	CXXFLAGS+=	-W -Wextra -Wall
	CXXFLAGS+=	-ansi -pedantic
endif

ifeq	($(DEBUG), 1)
	CXXFLAGS+=	-g -DDEBUG
endif

ifeq	($(WERROR), 1)
	CXXFLAGS+=	-Werror
endif

all:		$(NAME)

$(NAME):	$(DEPS) $(OBJS)
		ar -rc $(NAME) $(OBJS)
		ranlib $(NAME)
ifeq	($(DEBUG), 1)
		@echo "\033[33;32m=== Compilation in debug mode\t\t\tDONE\033[33;39m"
endif

clean:
		@echo "\033[33;32m=== Suppresion des fichiers objets\033[33;39m"
		$(RM) $(OBJS) $(DEPS)

fclean:		clean
		@echo "\033[33;32m=== Suppression de l'executable\033[33;39m"
		$(RM) $(NAME)

re:		fclean all

## Regles speciales

%.depend:	%.cpp
		@$(CXX) $(CXXFLAGS) -MM -o $@ $<
		@sed -i -e 's|.*:|$*.o:|' $@

-include $(DEPS)

.PHONY:	all clean fclean re lib
