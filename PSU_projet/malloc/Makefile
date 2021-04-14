##
## EPITECH PROJECT, 2019
## B-PSU-400-MAR-4-1-malloc-antoine.viala
## File description:
## Makefile
##

INC_DIR		= include/

CC		= gcc
CFLAGS		+= -I $(INC_DIR)
CFLAGS		+= -Wall -Wextra -Werror -Wno-deprecated
CFLAGS		+= -fPIC

RM		= rm -f

NAME		= libmy_malloc.so

SRCS_DIR	= src/
SRCS_FILES	= malloc.c \
		free.c \
		calloc.c \
		realloc.c \
		reallocarray.c \

SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS		= $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -fPIC -shared -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

