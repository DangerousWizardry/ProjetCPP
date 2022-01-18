#include "MyString.h"
#include <iostream>
#include <string>

int main(){
	MyString mystring1;
	char myword[] = { 'H', 'e', 'l', 'l', 'o', '\0' }; 
	mystring1 = myword;
	MyString mystring2;
	mystring2 = myword;
	MyString mystring3 = mystring2 + mystring1;
	std::cout << "mystring capacity is " << mystring3.capacity() << std::endl;
	for(int i=0;i<11;i++){
		std::cout << mystring3._char_array[i] << std::endl;
	}
	 // std::string str1 = "hello";
	// mystring += str1;
	// std::cout << "mystring size is " << mystring->length() << std::endl;
	return 0;
}