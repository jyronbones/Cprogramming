CC = gcc
CFLAGS = -g -Wall -ansi -pedantic -w
OUT_EXE = lab45

$(OUT_EXE): main.o functions.o functions.h
	$(CC) $(CFLAGS) -o $(OUT_EXE) main.o functions.o

main.o: main.c functions.h
	$(CC) $(CFLAGS) -c main.c

functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c

clean:
	rm *.o lab45