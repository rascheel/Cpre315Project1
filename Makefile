compress: compress.o Node.o
	g++ -o ./bin/compress.exe compress.o Node.o -std=c++0x

compress.o: compress.cpp Node.h
	g++ -c compress.cpp -std=c++0x

Node.o: Node.h Node.cpp
	g++ -c Node.cpp -std=c++0x

clean:
	rm *.o
	rm ./bin/*.exe 
