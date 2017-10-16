CFLAGS = -Wall -g
DEPS = logfind.h

%.o: %.c %(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

logfind: main.o get_filenames.o
	$(CC) $(CFLAGS) -o logfind main.o get_filenames.o

clean:
	ls | grep -v ".c" | grep -v ".h" | grep -v ".txt" | grep -v Makefile | grep ".o"| xargs rm


