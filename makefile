all: main
	gcc main.c cesar.c vigenere.c

main: main.c  cesar.o vigenere.o
	gcc vigenere.o cesar.o main.c -o main

clean:
	rm main *.o a.out

cesar.o: cesar.c cesar.h
	gcc -c cesar.c

vigenere.o: vigenere.c vigenere.h
	gcc -c vigenere.c