MedianOfMatrix: MedianOfMatrix.o
	g++ -g -o MedianOfMatrix.exe MedianOfMatrix.o -pthread    

MedianOfMatrix.o: MedianOfMatrix/MedianOfMatrix.cpp
	g++ -g  -c -pthread MedianOfMatrix/MedianOfMatrix.cpp
