UNAME_S = $(shell uname -s)
ifeq ($(OS),Windows_NT)
ILDIRS = -I.\include/ -I. -L.\lib/
else
ifeq ($(UNAME_S),Linux)
ILDIRS = -Iinclude -I. -Llib
clean:
	rm $(OBJ)
endif
endif
SRC = $(wildcard Core/*.cpp) $(wildcard Core/**/*.cpp) $(wildcard Core/**/**/*.cpp) $(wildcard Core/**/**/**/*.cpp)
OBJ = $(wildcard *.o)

all: glad cc

glad:
	gcc -c -fPIC glad.c $(ILDIRS)

cc:
	g++ -c -fPIC $(SRC) $(ILDIRS)
