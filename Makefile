
NAME	=	my_pokemon

SRCS	=	src/main.cpp						\
		src/game/PokemonModele/PokemonModele.cpp

OBJS	=	$(SRCS:.cpp=.o)

LIBS	=

INCLUDE	=	-I include/	\
		$(foreach LIB, $(LIBS), -I lib/$(LIB)/include/)

RM	=	rm -f

CXXFLAGS	+=	$(INCLUDE)

LDFLAGS	+=	$(foreach LIB, $(LIBS), -L lib/$(LIB) -l $(LIB))

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
		$(RM) $(OBJS)

fclean:		fcleanlib clean
		@echo "\033[33;32m=== Suppression de l'executable\033[33;39m"
		$(RM) $(NAME)

re:		fclean all

## Compilation de la lib

lib:
		@echo "\033[33;32m=== Compilation des libs\033[33;39m"
		$(foreach LIB, $(LIBS), @$(MAKE) -sC lib/$(LIB) all CLANG=$(CLANG) DEBUG=$(DEBUG);)

cleanlib:
		$(foreach LIB, $(LIBS), @$(MAKE) -sC lib/$(LIB) clean;)

fcleanlib:
		$(foreach LIB, $(LIBS), @$(MAKE) -sC lib/$(LIB) fclean;)

relib:
		$(foreach LIB, $(LIBS), @$(MAKE) -sC lib/$(LIB) re CLANG=$(CLANG) DEBUG=$(DEBUG);)

.PHONY:		all clean fclean re lib cleanlib fcleanlib relib
