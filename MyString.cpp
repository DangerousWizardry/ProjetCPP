#include "MyString.h"

MyString::MyString(){
	//TODO Lucas
	_max_size = 100;
	_alloc_size = 4;
	_char_array = new char[_alloc_size];
	_char_array[0] = '\0';
}

MyString::MyString(char * char_array){
	//TODO Léa
}

MyString::~MyString(){
	//TODO Lucas
	delete[] _char_array;
}

MyString::MyString(const MyString& string_to_copy){
	//TODO Alix
}

const char * MyString::c_str(){
	//TODO Alix
}

size_t MyString::size(){
	//TODO Alix
}

size_t MyString::length(){
	//TODO Léa
}

size_t MyString::capacity(){
	return _alloc_size;
}

size_t MyString::max_size(){
	//TODO Léa
}

void MyString::clear(){
	//TODO Alix
}

bool MyString::empty(){
	return this->length() == 0;
}

void MyString::resize(int new_size, char c){
	//TODO Léa
}

void MyString::reserve(size_t n){
	//TODO Lucas
	int str_size = this->length();
	if(n>str_size){
		char * new_array = new char[n];
		for (int i=0; i < str_size + 1; i++){
			new_array[i] = _char_array[i];
		}
		char * to_be_deleted = _char_array;
		_char_array = new_array;
		delete to_be_deleted;
	}
	else{
		//Throw Error
	}
}

MyString& MyString::operator=(const std::string& str){
	//TODO Léa
}

MyString& MyString::operator=(const char * str){
	//TODO Lucas
}

MyString& MyString::operator=(const char str){
	//TODO Alix
}

MyString& MyString::operator+(const std::string& str){
	//TODO Lucas
}

MyString& MyString::operator+(const char * str){
	//TODO Alix
}

MyString& MyString::operator+(const char str){
	//TODO Léa
}