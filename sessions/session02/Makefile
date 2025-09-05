all: index loop prueba

index: index.o
	${CC} -o $@ $<

index.o: index.c
	${CC} -c $<

loop: loop.o
	${CC} -c $<

loop.o: loop.c
	${CC} -c $<

prueba: prueba.o
	${CC} -o $@ $<

prueba.o: prueba.c
	${CC} -c $<

clean:
	rm -f *.o index loop prueba
	rm -f *~
