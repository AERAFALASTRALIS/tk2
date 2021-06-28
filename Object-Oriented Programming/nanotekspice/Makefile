##
## EPITECH PROJECT, 2021
## make
## File description:
## make
##

CC = g++

CFLAGS	+= -Wall -Iinclude -Iinclude/component -Iinclude/gate -O3 -std=c++14
LDFLAGS	+=

SRC = $(addprefix src/, \
	AComponent.cpp \
	$(addprefix component/, \
	2716.cpp \
	4001.cpp \
	4008.cpp \
	4011.cpp \
	4013.cpp \
	4017.cpp \
	4030.cpp \
	4040.cpp \
	4069.cpp \
	4071.cpp \
	4081.cpp \
	4094.cpp \
	4512.cpp \
	4514.cpp \
	4801.cpp \
	Input.cpp \
	Output.cpp \
	Clock.cpp \
	True.cpp \
	False.cpp \
	Logger.cpp) \
	AGate.cpp \
	$(addprefix gate/, \
	GateAnd.cpp \
	GateBin3ToDec8.cpp \
	GateBin4ToDec16.cpp \
	GateBuffer.cpp \
	GateCounter.cpp \
	GateFlipFlop.cpp \
	GateInput.cpp \
	GateLogger.cpp \
	GateNand.cpp \
	GateNor.cpp \
	GateNot.cpp \
	GateOr.cpp \
	GateOutput.cpp \
	GateSum.cpp \
	GateXor.cpp) \
	main.cpp \
	Parser.cpp \
	Pin.cpp)

NAME	= nanotekspice

OBJ 	= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
