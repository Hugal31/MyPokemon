##
## Makefile for my_pokemon in /home/laloge_h/projets/Perso/C++/MyPokemon
##
## Made by Hugo Laloge
## Login   <laloge_h@epitech.net>
##
## Started on  Wed May 27 07:45:50 2015 Hugo Laloge
## Last update Wed May 27 22:00:44 2015 Hugo Laloge
##

NAME	=	my_pokemon

include	sources.mk

OBJS	=	$(SRCS:.cpp=.o)

DEPS	=	$(SRCS:.cpp=.d)

LIBS	=

INCLUDE	=	$(foreach LIB, $(LIBS), -I lib/$(LIB)/include/)		\
		-I include/						\
		-I /usr/local/lib/boost_1_58_0/include/			\

RM	=	rm -f

CXXFLAGS	+=	-std=c++11
CXXFLAGS	+=	$(INCLUDE)

LDFLAGS	+=	$(foreach LIB, $(LIBS), -L lib/$(LIB) -l $(LIB))	\
		-L/usr/local/lib/boost_1_58_0/lib			\
		-lboost_program_options

CLANG	?=	0

DEBUG	?=	0

ifeq ($(CLANG), 1)
	CXX	=	clang++
	CXXFLAGS	+=	-Weverything -Wno-padded
else
	CXX	=	g++
	CXXFLAGS	+=	-W -Wextra -Wall
	CXXFLAGS	+=	-ansi -pedantic
endif

ifeq	($(DEBUG), 1)
	CXXFLAGS	+=	-g -DDEBUG=1
endif

all:		lib $(NAME)

$(NAME):	$(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
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

## Regles speciales

%.o:	%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	@$(CXX) $(CXXFLAGS) -MM -o $*.d $<
	@sed -i -e 's|.*:|$*.o:|' $*.d

-include $(DEPS)

.PHONY:	all clean fclean re lib cleanlib fcleanlib relib
