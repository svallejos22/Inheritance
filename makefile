C = g++
CFLAGS = -Wall - g
DEPS = employee.h

main : main.o employee.o
$(CC) $(CFLAGS) - o main main.o employee.o

main.o : main.cpp employee.h
$(CC) $(CFLAGS) - c main.cpp
employee.o : employee.h

clean : -rm main.o employee.o