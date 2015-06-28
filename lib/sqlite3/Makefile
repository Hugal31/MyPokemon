NAME	=	libsqlite3.a

SRCS	=	src/sqlite3.c						\

OBJS	=	$(SRCS:.c=.o)

INCLUDE	=	include

CFLAGS	+=	$(foreach PATH, $(INCLUDE), -I $(PATH))

CLANG	?=	0

DEBUG	?=	0

RM	?=	rm -f

AR	?=	ar

ifeq	($(CLANG), 1)
CC	=	clang
else
CC	=	gcc
endif

ifeq	($(DEBUG), 1)
CFLAGS	+=	-g
endif

all:	$(NAME)

$(NAME):	$(OBJS)
		$(AR) -rc $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
