all: Go

clean:
	rm Go dessine.o libdessine.a
	
Go: Go.c dessine.h libdessine.a
	gcc -g Go.c -o Go -L. -ldessine -lX11 -lm

libdessine.a: dessine.c dessine.h
	gcc -g -c dessine.c
	ar -r libdessine.a dessine.o
	
