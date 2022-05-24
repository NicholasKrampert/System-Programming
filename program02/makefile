main: main.o histo.o
	gcc -o main main.o histo.o

main.o: main.c histo.h
	gcc -c main.c

histo.o: histo.c histo.h
	gcc -c histo.c

clean:
	rm  main main.o histo.o
