#the compiler
CC = g++

#variables
SRC = src/main.cpp src/Game.cpp src/TextureManager.cpp src/GameObject.cpp src/Map.cpp src/SpriteSystem.cpp src/SpriteComponent.cpp src/Math.cpp src/ColliderComponent.cpp
Obj = main.o


#targets
all: main
	./demo

main: main.o
	 $(CC)  -o demo $(SRC)  -lSDL2 -lSDL2_image

main.o: src/main.cpp src/Game.cpp src/TextureManager.cpp src/GameObject.cpp src/Map.cpp src/SpriteSystem.cpp src/SpriteComponent.cpp src/Math.cpp src/ColliderComponent.cpp
	  $(CC) -c  $(SRC)   $(pkg-config --cflags --libs sdl2)


clean:
	rm -rf *.o demo