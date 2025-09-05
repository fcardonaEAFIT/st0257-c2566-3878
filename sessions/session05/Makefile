all: HelloWorld

HelloWorld: HelloWorld.o
	${CC} -o HelloWorld HelloWorld.o

HelloWorld.o: HelloWorld.c
	${CC} -c HelloWorld.c

clean:
	rm -f HelloWorld *.o
	rm *~
