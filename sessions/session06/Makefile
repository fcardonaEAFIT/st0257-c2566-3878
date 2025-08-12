all: proceso cesarcipher

proceso: proceso.o
	gcc -o proceso proceso.o

proceso.o: proceso.c
	gcc -c proceso.c

cesarcipher: cesarcipher.o
	gcc -o cesarcipher cesarcipher.o

cesarcipher.o: cesarcipher.c
	gcc -c cesarcipher.c

clean:
	rm -f *.*~ *~
	rm -f proceso cesarcipher
	rm -f proceso.o cesarcipher.o
