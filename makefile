ANALISE ?= 0
all: main

main: ./src/leitura.c ./src/solver.c ./src/menu.c ./src/main.c
ifeq ($(ANALISE),1)
	gcc -D ANALISE ./src/leitura.c ./src/solver.c ./src/menu.c ./src/main.c -o main
else
	gcc ./src/leitura.c ./src/solver.c ./src/menu.c ./src/main.c -o main
endif
