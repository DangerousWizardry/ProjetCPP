#include "MyString.h"
#include <iostream>
#include <string>

int main(){
	char myword[] = { 'H', 'e', 'l', 'l', 'o', '\0' }; 
	char mychar = 'c';
	//String creation
	MyString default_str = MyString();
	std::cout << "Default string created" << std::endl;
	MyString chararr_str = MyString(myword);
	std::cout << "Char Array string" << std::endl;
	MyString copy_str = MyString(chararr_str);
	std::cout << "Copy String created" << std::endl;


	//Look for content
	std::cout << chararr_str.c_str() << std::endl;
	std::cout << copy_str.c_str() << std::endl;

	std::cout << chararr_str.size() << std::endl;
	std::cout << chararr_str.capacity() << std::endl;


	//Operator = overload
	MyString fromChar = MyString();
	MyString fromMyString = MyString();
	MyString fromCharArray = MyString();

	fromChar = mychar;
	fromMyString = chararr_str;
	fromCharArray = myword;

	std::cout << fromChar.c_str() << std::endl;
	std::cout << fromMyString.c_str() << std::endl;
	std::cout << fromCharArray.c_str() << std::endl;

	//Operator + overload
	MyString add_str = copy_str + chararr_str;
	MyString add_chararr = copy_str + myword;
	MyString add_char = copy_str + mychar;

	std::cout << add_str.size() << std::endl;
	std::cout << add_str.capacity() << std::endl;

	std::cout << add_str.c_str() << std::endl;
	std::cout << add_chararr.c_str() << std::endl;
	std::cout << add_char.c_str() << std::endl;

	//Resize
	add_char.resize(100,'a');
	std::cout << add_char.c_str() << std::endl;
	try{
		add_char.resize(101,'a');
	}
	catch(std::length_error err){
		std::cout << "Got a valid exception :" << std::endl;
		std::cout << err.what() << std::endl;
	}
	return 0;
}