all: main clear

main: leitura.o solver.o main.o
	gcc leitura.o solver.o main.o -o main

leitura.o: ./src/leitura.c
	gcc -c ./src/leitura.c -o leitura.o

solver.o: ./src/solver.c
	gcc -c ./src/solver.c -o solver.o

main.o: ./src/main.c
	gcc -c ./src/main.c -o main.o

clear:
	rm *.o