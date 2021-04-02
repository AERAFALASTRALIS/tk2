##
## EPITECH PROJECT, 2020
## B-CPP-300-MAR-3-1-CPPD03-antoine.viala
## File description:
## Makefile
##

NAME = libstring.a

FILES = my_string.c \
	my_assign.c

INCLUDES = 

FLAGS = -std=gnu11 -Wall -Wextra

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

prepush:	fclean
	git add --all
	git status

tree:	prepush
	tree -a -I .git

push:	prepush
	git commit -m 'auto-sync with master'
	git push origin master

pull:
	git pull origin master

sync:	pull	push

debug:
	clear
	gcc -g3 -o $(NAME) $(FILES) -Wall -Wextra $(FLAGS) $(INCLUDES)

valgrind:
	clear
	gcc -g3 -o $(NAME) $(FILES) $(FLAGS) $(INCLUDES)

update:
	mmkfile $(NAME) "$(FLAGS)"
