#paths
INCLUDE = ./include
SRC = ./src

#compiler
CC = g++

#compile options
CPPFLAGS = -Wall -Werror -Wextra -std=c++11 -ggdb -I$(INCLUDE)

OBJS = $(SRC)/main.o $(SRC)/list.o $(SRC)/school.o

EXEC = main

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC)

valgrind: $(EXEC)
	valgrind ./$(EXEC)
