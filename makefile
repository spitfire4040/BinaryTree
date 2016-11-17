CC=g++
CXXFLAGS= -g -Wall -std=c++0x

all:		run

run:		main.o tree.o
			$(CC) $(CXXFLAGS) -o run main.o tree.o

main.o:		main.cpp
			$(CC) $(CXXFLAGS) -c main.cpp

tree.o:	tree.cpp tree.h
			$(CC) $(CXXFLAGS) -c tree.cpp

clean:		
			\rm *.o run
