CFLAGS=-Wall -g

targets := $(wildcard *.c) 

all:	ex1 ex3 ex7 ex8 ex9 ex10 ex11 ex12 ex13 ex14 ex15 ex16 ex17 ex18 ex19

clean:
	ls | grep -v "\." | grep -v Makefile | xargs rm
