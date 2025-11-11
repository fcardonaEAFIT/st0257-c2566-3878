all: create_process catw

create_process: create_process.o
	${CC} -o $@ $<

create_process.o: create_process.c
	${CC} -c $<

catw: catw.o
	${CC} -o $@ $<

catw.o: catw.c
	${CC} -c $<


clean:
	rm -f create_process catw
	rm -f *.o
	rm -f *~
