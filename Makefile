all:
	clang++ -c -std=c++1z ./Engine/*.cpp *.cpp
	clang++ -lGLEW -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -lSOIL -o program *.o

clean:
	rm *.o program
