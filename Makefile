all: program

program: maps.o driver.o
	g++ maps.o driver.o -o map

maps.o: maps.cpp
	g++ -c maps.cpp

driver.o: driver.cpp
	g++ -c driver.cpp

clean:
	rm -rf *.o program
