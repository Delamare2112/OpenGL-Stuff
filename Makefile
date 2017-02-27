all:
	clang++ -lGLEW -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -std=c++1z *.cpp -o program
