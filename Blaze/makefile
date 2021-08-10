ILDIRS = -Iinclude -I. -Llib
SRC = $(wildcard Core/*.cpp) $(wildcard Core/**/*.cpp) $(wildcard Core/**/**/*.cpp) $(wildcard Core/**/**/**/*.cpp)
OBJ = $(wildcard *.o)

all: glad cc

glad:
	gcc -c -fPIC glad.c $(ILDIRS)

cc:
	g++ -c -fPIC $(SRC) $(ILDIRS)

clean:
	rm $(OBJ)
