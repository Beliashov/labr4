all: app

app: main.o sort.o
	gcc main.o sort.o -o app

main.o: main.c sort.h
	gcc -c main.c -o main.o

sort.o: sort.c sort.h
	gcc -c sort.c -o sort.o

clean:
	rm -f main.o sort.o app
