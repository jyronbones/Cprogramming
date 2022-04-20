CC = gcc
CFLAGS = -g -Wall -ansi -pedantic -w
OUT_EXE = a2

$(OUT_EXE): main.o employee.o functions.o functions.h
	$(CC) $(CFLAGS) -o $(OUT_EXE) main.o employee.o functions.o

main.o: main.c functions.h
	$(CC) $(CFLAGS) -c main.c

employee.o: employee.c functions.h
	$(CC) $(CFLAGS) -c employee.c

functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c

clean:
	rm *.o a2