all:
	g++ ./src/main.cpp ./src/visualization.cpp ./src/annealing.cpp -o ./bin/res.out -std=c++17 -I./include/ -L./lib/ -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system && export LD_LIBRARY_PATH=${CURDIR}/lib && ./bin/res.out

