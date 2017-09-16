CFLAGS=-Wall -g

targets := $(wildcard *.c) 

all:	ex1 ex3 ex7

clean:
	ls | grep -v "\." | grep -v Makefile | xargs rm
