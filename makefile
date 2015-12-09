Assignment3: Assignment3.o readerWriter.o
	g++ Assignment3.o readerWriter.o -o Assignment3 -pthread

Assignment3.o: ReaderWriter Assignment3.cpp
	g++ -c Assignment3.cpp -pthread -fpermissive

readerWriter.o: ReaderWriter readerWriter.cpp
	g++ -c readerWriter.cpp -pthread -fpermissive 

clean:
	rm *.o Assignment3
