all: jardin jardin_limite fumadores

jardin: jardin.o
	${CXX} -o $@ $< -lpthread

jardin.o: jardin.cpp
	${CXX} -c $<

jardin_limite: jardin_limite.o
	${CXX} -o $@ $< -lpthread

jardin_limite.o: jardin_limite.cpp
	${CXX} -c $<

fumadores: fumadores.o
	${CXX} -o $@ $< -lpthread

fumadores.o: fumadores.cpp
	${CXX} -c $<

clean:
	rm -f *.o
	rm -f *~
	rm -f fumadores jardin jardin_limite
