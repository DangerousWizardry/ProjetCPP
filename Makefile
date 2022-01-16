CXXFLAGS=-Wall

project: main.o MyString.o
	g++ main.o MyString.o -o main.exe
main.o: main.cpp MyString.h
	g++ -c main.cpp -o main.o
MyString.o: MyString.cpp MyString.h
	g++ -c MyString.cpp -o MyString.o
clean:
	rm main.o MyString.o main.exe