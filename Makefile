all:
	g++ -I src/include -L src/lib -o main src/main.cpp src/window.cpp src/rect.cpp src/ball.cpp -l mingw32 -l SDL2main -l SDL2 -I window -I rect -I ball