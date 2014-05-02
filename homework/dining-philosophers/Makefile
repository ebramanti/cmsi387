dining-philosopher: philosopher.o utility.o
	gcc -o dining-philosopher *.o -lpthread

philosopher.o: utility.h

utility.o: utility.h

clean:
	rm dining-philosopher *.o
