all: direccion

direccion: direccion.o
	${CC} -o $@ $<

direccion.o: direccion.c
	${CC} -c $<

clean:
	rm -f direccion direccion.o
	rm -f *~
