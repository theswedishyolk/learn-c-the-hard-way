CFLAGS=-Wall -g -DNDEBUG


all:	ex1 ex3 ex7 ex8 ex9 ex10 ex11 ex12 ex13 ex14 ex15 ex16 ex17 ex18 ex19 ex22main ex23 ex24

ex22main: ex22
	$(CC) $(CFLAGS) ex22_main.c ex22.o -o ex22_main

ex22:
	$(CC) $(CFLAGS) -c -o ex22.o ex22.c

clean:
	ls | grep -v "\." | grep -v Makefile | xargs rm
	rm *.o
