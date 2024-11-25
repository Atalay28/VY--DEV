make: derle bagla calistir

derle:
	g++ -I "./include/" -o ./lib/main.o -c ./src/main.cpp
	g++ -I "./include/" -o ./lib/gendugum.o -c ./src/gendugum.cpp
	g++ -I "./include/" -o ./lib/kromozom.o -c ./src/kromozom.cpp
	g++ -I "./include/" -o ./lib/kromodugum.o -c ./src/kromodugum.cpp
	
bagla:
	g++ -I ./include/ -o ./bin/program ./lib/main.o ./lib/gendugum.o ./lib/kromozom.o ./lib/kromodugum.o 

calistir:
	./bin/program
