all: app

app: main.o sort_methods.o
	gcc main.o sort_methods.o -o app

main.o: main.c sort_methods.h
	gcc -c main.c -o main.o

sort_methods.o: sort_methods.c sort_methods.h
	gcc -c sort_methods.c -o sort_methods.o

clean:
	rm -f main.o sort_methods.o app
