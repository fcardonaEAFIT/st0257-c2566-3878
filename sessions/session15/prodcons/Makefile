all: prodcons seminit productor consumidor

prodcons: prodcons.o
	${CC} -o $@ $< -lpthread

prodcons.o: prodcons.c
	${CC} -c $<

seminit: seminit.o
	${CC} -o $@ $< -lpthread

seminit.o: seminit.c
	${CC} -c $<

productor: productor.o
	${CC} -o $@ $<

productor.o: productor.c
	${CC} -c $<

consumidor: consumidor.o
	${CC} -o $@ $<

consumidor.o: consumidor.c
	${CC} -c $<

clean:
	rm -f *.o
	rm -f *~
	rm -f prodcons seminit productor consumidor
