##
## EPITECH PROJECT, 2021
## make
## File description:
## make
##

NAME = z

FILES = z.c


all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(FILES)

fast:
	gcc -Ofast -o $(NAME) $(FILES)

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
	gcc -g3 -o $(NAME) $(FILES) -Wall -Wextra

valgrind:
	clear
	gcc -g3 -o $(NAME) $(FILES)

update:
	mmkfile $(NAME) "$(FLAGS)"
