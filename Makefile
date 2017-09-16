CFLAGS=-Wall -g

targets := $(wildcard *.c) 

all:	ex1 ex3 ex7 ex8 ex9 ex10 ex11

clean:
	ls | grep -v "\." | grep -v Makefile | xargs rm
