ANALISE ?= 0

.PHONY: all

all: main

main: ./src/leitura.c ./src/solver.c ./src/menu.c ./src/main.c
ifeq ($(ANALISE),1)
	gcc -D ANALISE ./src/leitura.c ./src/solver.c ./src/menu.c ./src/main.c -o main
else
	gcc ./src/leitura.c ./src/solver.c ./src/menu.c ./src/main.c -o main
endif

clean:
ifeq ($(OS),Windows_NT)
	del main
else
	rm main
endif
