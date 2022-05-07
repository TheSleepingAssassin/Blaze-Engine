UNAME_S = $(shell uname -s)
ifeq ($(OS),Windows_NT)
ILDIRS = -I.\Blaze\include/ -I. -L.\Blaze\lib/
LIBS = -l:libglfw3dll.a -lopengl32
all:
	.\Run.bat
build:
	g++ $(OBJ) $(ILDIRS) $(LIBS) $(ENGINE).so -o a.exe
run:
	./a.exe
clean:
	clean.bat
else
ifeq ($(UNAME_S),Linux)
ILDIRS = -IBlaze/include -I. -LBlaze/lib
LIBS = -l:libglfw3.a -lGL -ldl -lX11 -lpthread
all:
	chmod +x Run.sh
	./Run.sh
build:
	g++ $(OBJ) $(ILDIRS) $(LIBS) ./$(ENGINE).so -o a.out
run:
	./a.out
clean:
	rm $(OBJ) $(ENGINE).so a.out
endif
endif
SRC = $(wildcard src/*.cpp)
OBJ = $(wildcard *.o)
EOBJ = $(wildcard Blaze/*.o)
ENGINE = Blaze

EB:
	g++ -shared $(EOBJ) $(ILDIRS) $(LIBS) -o $(ENGINE).so

cc:
	g++ -c $(SRC) $(ILDIRS)
