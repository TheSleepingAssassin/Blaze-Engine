ILDIRS = -IBlaze/include -I. -LBlaze/lib
LIBS = -l:libglfw3.a -lGL -ldl -lX11 -lpthread
SRC = $(wildcard src/*.cpp)
OBJ = $(wildcard *.o)
EOBJ = $(wildcard Blaze/*.o)
ENGINE = Blaze

all:
	chmod +x Run.sh
	./Run.sh

EB:
	g++ -shared $(EOBJ) $(ILDIRS) $(LIBS) -o $(ENGINE).so

cc:
	g++ -c $(SRC) $(ILDIRS)

build:
	g++ $(OBJ) $(ILDIRS) $(LIBS) ./$(ENGINE).so

run:
	./a.out

clean:
	rm $(OBJ) $(ENGINE).so a.out
