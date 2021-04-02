##
## EPITECH PROJECT, 2021
## B-CPP-300-MAR-3-1-CPPD06-antoine.viala
## File description:
## Makefile
##

NAME = my_cat

FILES = my_cat.cpp

INCLUDES = 

FLAGS = 

all:	$(NAME)

$(NAME):
	g++ -o $(NAME) $(FILES) $(FLAGS) $(INCLUDES)

fast:
	g++ -Ofast -o $(NAME) $(FILES) $(FLAGS) $(INCLUDES)

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
	g++ -g3 -o $(NAME) $(FILES) -Wall -Wextra $(FLAGS) $(INCLUDES)

valgrind:
	clear
	g++ -g3 -o $(NAME) $(FILES) $(FLAGS) $(INCLUDES)

update:
	mmkfile $(NAME) "$(FLAGS)"
