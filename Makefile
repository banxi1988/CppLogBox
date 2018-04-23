CC=clang++
CFLAGS=-std=c++14

main: main.o LogLevel.o Utils.o BaseDestination.o ConsoleDestination.o LogBox.o
	$(CC) ${CFLAGS} -o main  main.o LogLevel.o Utils.o BaseDestination.o ConsoleDestination.o LogBox.o

LogLevel.o : LogLevel.cpp
	$(CC) ${CFLAGS} -c LogLevel.cpp 

Utils.o : Utils.cpp
	$(CC) ${CFLAGS} -c Utils.cpp 

BaseDestination.o : BaseDestination.cpp
	$(CC) ${CFLAGS} -c BaseDestination.cpp 

ConsoleDestination.o : ConsoleDestination.cpp
	$(CC) ${CFLAGS} -c ConsoleDestination.cpp 

LogBox.o : LogBox.cpp
	$(CC) ${CFLAGS} -c LogBox.cpp 

main.o : main.cpp
	$(CC) ${CFLAGS} -c main.cpp 


.PHONY: clean
clean:
	rm *.o

