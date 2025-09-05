all: dirInicio dirInicio2 quienEsMiPadre

dirInicio: dirInicio.o
	${CC} -o $@ $<

dirInicio.o: dirInicio.c
	${CC} -c $<

dirInicio2: dirInicio2.o
	${CC} -o $@ $<

dirInicio2.o: dirInicio2.c
	${CC} -c $<

quienEsMiPadre: quienEsMiPadre.o
	${CC} -o $@ $<

quienEsMiPadre2.o: quienEsMiPadre.c
	${CC} -c $<

clean:
	rm *.o dirInicio dirInicio2 quienEsMiPadre
	rm *~
