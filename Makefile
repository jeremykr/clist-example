PROG = main
CC = gcc
CFLAGS = -Wall
OBJS = main.o List.o Node.o MergeSort.o QuickSort.o

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o *.exe