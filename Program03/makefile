main: main.o queue.o
	gcc -o main main.o queue.o
main.o: main.c queue.h
	gcc -c -Wall main.c
queue.o: queue.c queue.h
	gcc -Wall -c queue.c
