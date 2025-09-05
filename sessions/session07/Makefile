all: copyfile

copyfile: copyfile.o handleerror.o
	gcc -o copyfile copyfile.o handleerror.o

handleerror.o: handleerror.c handleerror.h
	gcc -c handleerror.c

copyfile.o: copyfile.c handleerror.h
	gcc -c copyfile.c

clean:
	rm -f *.o
	rm -f *~ 
	rm -f copyfile
