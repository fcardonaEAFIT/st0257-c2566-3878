all: create_process catl liblnzctl.a crear_proceso

create_process: create_process.o
	${CC} -o $@ $<

create_process.o: create_process.c
	${CC} -c $<

crear_proceso: crear_proceso.o
	${CC} -o $@ $< -L${HOME}/lib -llnzctl

crear_proceso.o: crear_proceso.c tuberia_info.h
	${CC} -c $<

liblnzctl.a: lanzar_catl.o
	ar r $@ $<

catl: catl.o
	${CC} -o $@ $<

catl.o: catl.c
	${CC} -c $<

lanzar_catl.o: lanzar_catl.c tuberia_info.h
	${CC} -c $<

clean:
	rm -f create_process catl crear_proceso liblnzctl.a
	rm -f *.o
	rm -f *~
