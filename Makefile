##
## Makefile for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
##
## Made by Hugo Laloge
## Login   <laloge_h@epitech.net>
##
## Started on  Wed May 27 07:45:50 2015 Hugo Laloge
## Last update Thu Jun 18 17:14:30 2015 Hugo Laloge
##

NAME	=	MyPokemon

include	sources.mk

OBJS	=	$(SRCS:.cpp=.o)

DEPS	=	$(SRCS:.cpp=.depend)

LIBS	=

INCLUDE	=	$(foreach LIB, $(LIBS), -I lib/$(LIB)/include/)		\
		-I include/						\
		-I /usr/local/lib/boost_1_58_0/include/			\

RM	=	rm -f

CXXFLAGS+=	-std=c++11
CXXFLAGS+=	$(INCLUDE)

LDFLAGS	+=	$(foreach LIB, $(LIBS), -L lib/$(LIB) -l $(LIB))	\
		-L/usr/local/lib/boost_1_58_0/lib			\
		-lboost_serialization					\

CLANG	?=	1

DEBUG	?=	0

WERROR	?=	0

ifeq ($(CLANG), 1)
	CXX	=	clang++
	CXXFLAGS+=	-Weverything -Wno-padded		\
			-Wno-exit-time-destructors		\
			-Wno-global-constructors		\
			-Wno-c++98-compat
else
	CXX	=	g++
	CXXFLAGS	+=	-W -Wextra -Wall
	CXXFLAGS	+=	-ansi -pedantic
endif

ifeq	($(DEBUG), 1)
	CXXFLAGS	+=	-g -DDEBUG=1
endif

ifeq	($(WERROR), 1)
	CXXFLAGS	+=	-Werror
endif

all:		lib depends $(NAME)

$(NAME):	$(OBJS)
		$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(NAME) $(OBJS)
ifeq	($(DEBUG), 1)
		@echo "\033[33;32m=== Compilation in debug mode\t\t\tDONE\033[33;39m"
endif

clean:		cleanlib
		@echo "\033[33;32m=== Suppresion des fichiers objets\033[33;39m"
		$(RM) $(OBJS) $(DEPS)

fclean:		fcleanlib clean
		@echo "\033[33;32m=== Suppression de l'executable\033[33;39m"
		$(RM) $(NAME)

re:		fclean all

## Compilation de la lib

lib:
		$(foreach LIB, $(LIBS), @$(MAKE) -sC lib/$(LIB) all CLANG=$(CLANG) DEBUG=$(DEBUG);)

cleanlib:
		$(foreach LIB, $(LIBS), @$(MAKE) -sC lib/$(LIB) clean;)

fcleanlib:
		$(foreach LIB, $(LIBS), @$(MAKE) -sC lib/$(LIB) fclean;)

relib:
		$(foreach LIB, $(LIBS), @$(MAKE) -sC lib/$(LIB) re CLANG=$(CLANG) DEBUG=$(DEBUG);)

depends:	$(DEPS)

## Regles speciales

%.depend:	%.cpp
		@$(CXX) $(CXXFLAGS) -MM -o $@ $<
		@sed -i -e 's|.*:|$*.o:|' $@

-include $(DEPS)

.PHONY:	all clean fclean re lib cleanlib fcleanlib relib
