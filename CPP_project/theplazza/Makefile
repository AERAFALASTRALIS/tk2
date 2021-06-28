##
## EPITECH PROJECT, 2019
## tmp
## File description:
## Makefile
##

NAME = plazza

FILES = src/parsing/Error.cpp		\
	src/parsing/Parsing.cpp		\
	src/cmd/Cmd.cpp 		\
	src/reception/Reception.cpp	\
	src/kitchen/Kitchen.cpp		\
	src/kitchen/Factory.cpp		\
	src/tools/Mutex.cpp		\
        src/tools/Thread.cpp		\
	src/tools/ThreadPool.cpp	\
	src/tools/Process.cpp		\
	src/tools/Pipe.cpp		\
	src/pizza/Pizza.cpp		\
	src/tools/ScopedLock.cpp	\
	src/tools/Log.cpp		\
	src/cooks/Cooks.cpp		\
        src/pizza/Regina.cpp		\
	src/pizza/Margarita.cpp		\
	src/pizza/Americana.cpp		\
	src/pizza/Fantasia.cpp		\
	src/main.cpp

INCLUDES = -ldl -pthread -I include/

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
