DEBUG ?= 1
all: main clear

main: leitura.o solver.o menu.o main.o
	gcc leitura.o solver.o menu.o main.o -o main

leitura.o: ./src/leitura.c
	gcc -c ./src/leitura.c -o leitura.o

solver.o: ./src/solver.c
	gcc -c ./src/solver.c -o solver.o

menu.o: ./src/menu.c
	gcc -c ./src/menu.c -o menu.o

# -D ANALISE
main.o: ./src/main.c
ifeq ($(DEBUG),1)
	gcc -D ANALISE -c ./src/main.c -o main.o
else
	gcc -c ./src/main.c -o main.o
endif
clear:
	rm *.o