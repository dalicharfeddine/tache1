test:  main.o dep.o 
	gcc  dep.o main.o  -o test -lSDL -lSDL_image -lm -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -g
dep.o:dep.c
	gcc -c dep.c -lSDL -lSDL_image -g
