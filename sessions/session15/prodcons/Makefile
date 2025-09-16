all: prodcons seminit

prodcons: prodcons.o
	${CC} -o $@ $< -lpthread

prodcons.o: prodcons.c
	${CC} -c $<

seminit: seminit.o
	${CC} -o $@ $< -lpthread

seminit.o: seminit.c
	${CC} -c $<
