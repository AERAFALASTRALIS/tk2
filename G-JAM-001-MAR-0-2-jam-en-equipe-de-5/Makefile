##
## EPITECH PROJECT, 2020
## 
## File description:
## Makefile
##

NAME = EarthDefense

FILES = core/Core.cpp \
	core/Earth.cpp \
	core/Game.cpp \
	core/Projectile.cpp \
	core/Spaceship.cpp \
	engine/Engine.cpp \
	engine/Entity.cpp \
	engine/EntityType.cpp \
	engine/GraphicEngine.cpp \
	main/main.cpp \
	menu/menu.cpp \
	musique/musique.cpp \
	story/Strory.cpp \
	tools/BaseThreadedModule.cpp \
	tools/Save.cpp \
	tools/ThreadManager.cpp

TESTS = 

TESTS_TARGET = core/Core.cpp \
	core/Earth.cpp \
	core/Game.cpp \
	core/Projectile.cpp \
	core/Spaceship.cpp \
	engine/Engine.cpp \
	engine/Entity.cpp \
	engine/EntityType.cpp \
	engine/GraphicEngine.cpp \
	menu/menu.cpp \
	musique/musique.cpp \
	story/Strory.cpp \
	tools/BaseThreadedModule.cpp \
	tools/Save.cpp \
	tools/ThreadManager.cpp

OBJ = $(FILES:.cpp=.o)

INCLUDES = 

CPPFLAGS = -I . -Wall -Wextra
CC = g++
BINFLAGS = -lm -lpthread -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -Wall -Wextra -o $(NAME) $(OBJ) $(BINFLAGS) $(INCLUDES)

single:
	clear && make -j8 && make clean

fast:
	$(CC) -Ofast -o $(NAME) $(FILES) $(CPPFLAGS) $(BINFLAGS) $(INCLUDES)

clean:
	rm -f $(OBJ)
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
	$(CC) -g3 -o $(NAME) $(FILES) -Wall -Wextra $(CPPFLAGS) $(BINFLAGS) $(INCLUDES)

valgrind:
	clear
	$(CC) -g3 -o $(NAME) $(FILES) $(CPPFLAGS) $(BINFLAGS) $(INCLUDES)

tests_run:
	$(CC) -o unit_tests $(TESTS_TARGET) $(TESTS) $(CPPFLAGS) $(BINFLAGS) $(INCLUDES) --coverage -lcriterion
	./unit_tests

coverage:
	clear
	make tests_run
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

update:
	./mmkfile "$(NAME)" "$(CPPFLAGS)" "$(BINFLAGS)"
