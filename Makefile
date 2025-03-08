CC=g++
CFLAGS=-I.


all:	PROJECT2

booksMain.o: booksMain.cc books.h
	$(CC) $(CFLAGS) -c booksMain.cc

program.o: program.cc books.h
	$(CC)  $(CFLAGS)  -c program.cc

PROJECT2: program.o booksMain.o
	$(CC) $(CFLAGS) -o PROJECT2 program.o booksMain.o

clean:
	rm -rf *.o
	rm -rf PROJECT2
