##
## EPITECH PROJECT, 2021
## make
## File description:
## make
##


SRCOBJ	=	objdumps/*.c

SRCNM	=	nms/*.c

OBJOBJ	=	$(SRCOBJ:.c=.o)

OBJNM	=	$(SRCNM:.c=.o)

NAMEOBJ	=	my_objdump

NAMENM	=	my_nm

CFLAGS	=	-Wall -Wextra -Werror

CC	=	gcc

all:	nm objdump

nm: $(NAMENM)

objdump: $(NAMEOBJ)

$(NAMENM):
	gcc $(SRCNM) -o $(NAMENM)

$(NAMEOBJ):
	gcc $(SRCOBJ) -o $(NAMEOBJ)

$(NM):	$(CC) $(SRCNM) -o $(NAMENM)

clean:
	rm -f $(OBJOBJ)
	rm -f $(OBJNM)

fclean: clean
	rm -f $(NAMENM)
	rm -f $(NAMEOBJ)

re:	fclean all
