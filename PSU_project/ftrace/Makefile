##
## EPITECH PROJECT, 2019
## B-PSU-402-MAR-4-1-strace-antoine.viala
## File description:
## Makefile
##

NAME = ftrace

FILES = main.c \
	print.c \
	child.c

INCLUDES = my.h

FLAGS = 

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(FILES) $(FLAGS) $(INCLUDES)

fast:
	gcc -Ofast -o $(NAME) $(FILES) $(FLAGS) $(INCLUDES)

clean:
	rm -f *.o
	rm -f *# *~ ./*/*# ./*/*~ ./*/*/*# ./*/*/*~ vgcore*

fclean:	clean
	rm -f $(NAME)

full:	update
	make re

fulld:	update
	make debug

re:	fclean all
