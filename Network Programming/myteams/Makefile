##
## EPITECH PROJECT, 2021
## make
## File description:
## make
##

SRCCLI	= src/client/main.c \
	  src/client/client.c \
	./lib/my_putstr.c \
	./lib/my_putchar.c \
        ./lib/my_put_nbr.c \
	./lib/testnbr.c	\
	./lib/my_getnbr.c

SRCSER	= src/server/main.c \
	  src/server/server.c \
        ./lib/my_putstr.c \
	./lib/my_putchar.c \
        ./lib/my_put_nbr.c \
	./lib/testnbr.c	\
	./lib/my_getnbr.c

OBJCLI	= $(SRCCLI:.c=.o)

OBJSER	= $(SRCSER:.c=.o)

NAMECLI	= myteams_cli

NAMESER	= myteams_server

CFLAGS	= -Wall -Wextra -Werror -Wshadow

CC	= gcc

all: myteams_server myteams_cli

myteams_server: $(NAMESER)

myteams_cli: $(NAMECLI)

$(NAMESER):
	gcc $(SRCSER) -o $(NAMESER)

$(NAMECLI):
	gcc $(SRCCLI) -o $(NAMECLI)

clean:
	rm -f $(OBJCLI)
	rm -f $(OBJSER)

fclean: clean
	rm -f $(NAMESER)
	rm -f $(NAMECLI)

re:	fclean all
