all: jardin

jardin: jardin.o
	${CXX} -o $@ $< -lpthread

jardin.o: jardin.cpp
	${CXX} -c $<
