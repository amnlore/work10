all: main.o dog.o
	gcc -o main main.o dog.o

main.o: main.c dog.h
	gcc -c main.c

dog.o: dog.c dog.h
	gcc -c dog.c

run:
	./main

clean:
	rm *.o
	rm main
