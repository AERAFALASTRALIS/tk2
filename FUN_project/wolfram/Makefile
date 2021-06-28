##
## EPITECH PROJECT, 2021
## make
## File description:
## make
##

NAME = wolfram

FILES = wolfram.hs

INCLUDES = 

FLAGS = 

all:	$(NAME)

$(NAME):
	ghc -o $(NAME) $(FILES) $(FLAGS) $(INCLUDES)

fast:
	ghc -o $(NAME) $(FILES) $(FLAGS) $(INCLUDES)

clean:
	rm -f *.o
	rm -f *.hi
	rm -f *.vg
	rm -f *.gc
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
