all: copyfile

copyfile: copyfile.o handleerror.o
	gcc -o copyfile copyfile.o handleerror.o

handleerror.o: handleerror.c handleerror.h
	gcc -c handleerror.c

copyfile.o: copyfile.c handleerror.h
	gcc -c copyfile.c

clean:
	rm -f copyfile.o handleerror.o
	rm -f copyfile.c~ handleerror.c~ Makefile~ handleerror.h~
	rm -f copyfile
