CC = gcc
CFLAGS = -Wall -lm

all: assignment_3

assignment_3: assignment_3.c
	$(CC) $(CFLAGS) -o assignment_3 assignment_3.c

clean:
	rm -f *.o assignment_3
