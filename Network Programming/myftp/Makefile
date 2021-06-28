##
## EPITECH PROJECT, 2021
## make
## File description:
## make
##

NAME		=	myftp

CC		=	gcc

CFLAGS		+=	-I ./include -g3 #-Wall -Wextra -Werror

RM		=	rm -f

SRCS		=	src/server.c			\
			src/tool.c			\
			src/init.c			\
			src/dir.c			\
			src/cmd.c			\
			src/cmdbis.c			\
			src/login.c			\
			src/list.c			\
			src/get_next_line.c		\
			src/my_str_to_wordtab.c

OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
