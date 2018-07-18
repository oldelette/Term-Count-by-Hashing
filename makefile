all:main.o
	gcc main.o -o hw6
main.o:main.c
	gcc -c main.c
clean:
	rm *.o	hw6