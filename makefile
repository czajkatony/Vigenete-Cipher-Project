MP1: main.o Cipher.o Pass.o
	g++ -std=c++11 -g -Wall main.o Cipher.o Pass.o -o MP1
main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
Cipher.o: Cipher.cpp Cipher.h
	g++ -std=c++11 -g -Wall -c Cipher.cpp
Pass.o: Pass.cpp Pass.h
	g++ -std=c++11 -g -Wall -c Pass.cpp
clean:
	rm *.o MP1
