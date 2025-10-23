all: helloworld byeworld helloworld-dyn programa

helloworld-dyn: helloworld.o
	${CC} -o $@ $<

helloworld: helloworld.o
	${CC} --static -o $@ $<

helloworld.o: helloworld.c
	${CC} -c $<

byeworld: byeworld.o
	${CC} --static -o $@ $<

byeworld.o: byeworld.c
	${CC} -c $<

programa: programa.o f.o g.o h.o
	${CC} -o $@ $^


clean:
	rm -f *.o
	rm -f *~
