compile:
	g++ -Wall -std=c++11 -g -pedantic test-map.cpp
	
a.out: compile
	
run: a.out
	./a.out
