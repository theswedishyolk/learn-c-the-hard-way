CFLAGS = -Wall -g
DEPS = logfind.h

%.o: %.c %(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

logfind: main.o get_filenames.o has_string.o
	$(CC) $(CFLAGS) -o logfind main.o get_filenames.o has_string.o

clean:
	$(RM) logfile *.o *~


