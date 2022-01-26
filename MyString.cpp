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
	int len = 0;
	while(char_array[len]!='\0') len++;
	reserve(len);
	_max_size=100;
	for (int i = 0; i<len+1 ; i++){
		_char_array[i]=char_array[i];
	}
}

MyString::~MyString(){
	//TODO Lucas
	delete[] _char_array;
}

MyString::MyString(const MyString& string_to_copy){
	//TODO Alix
	int len = string_to_copy.length();
	_char_array = new char[len+1];
	for (int i = 0; i<len+1; i++){
	    _char_array[i]=string_to_copy[i];
	}
	_char_array[len]='\0';
}

const char * MyString::c_str(){
	//TODO Alix
    char* result = new char[this->length()+1]; //je ne sais pas si c'est +1 ou pas
    for(int i=0; i<this->length();i++){
        result[i]=_char_array[i];
    }
    result[this->length()] = '\0';
    return result;
}

size_t MyString::size() const{
	//TODO Alix
	return this->length();
}

size_t MyString::length() const{
	//TODO Léa
	int len = 0;
	while (_char_array[len]!='\0'){
		len++;
	}
	return len;
}

size_t MyString::capacity(){
	return _alloc_size;
}

size_t MyString::max_size(){
	//TODO Léa
	return _max_size;
}

void MyString::clear(){
	//TODO Alix
	_char_array[0]= '\0';
}

bool MyString::empty(){
	return this->length() == 0;
}

void MyString::resize(int new_size, char c){
	//TODO Léa
	int str_size = this->length();
	reserve(new_size);
	if (new_size>str_size){
		for (int i=str_size; i<new_size+1 ; i++){
			_char_array[i] = c;
		}
	}
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
		_alloc_size = n;
	}
	else{
		//Throw Error
		std::cout << "You're trying to allocate a lower amount of memory than the amount needed to store the current string" << std::endl;
	}
}

MyString& MyString::operator=(const MyString& str){
	//TODO Léa
	int len = str.length();
	reserve(str._alloc_size); //reserve(len)   ???
	for (int i=0; i<len+1; i++){
		_char_array[i] = str._char_array[i];
	} //return _char_array ?? ou alors c'est pas obligé vu que c'est un objet de type MyString
	//return *this; ???
}

MyString& MyString::operator=(const char * str){
	//TODO Lucas
	int new_str_size = 0;
	while(str[new_str_size]!='\0') new_str_size++;
	if(_alloc_size < new_str_size + 1){
		int target_alloc = _alloc_size;
		do{
			target_alloc*=2;
		}while(target_alloc<new_str_size+1);
		reserve(target_alloc);
	}
	for(int i=0; i<new_str_size;i++){
		_char_array[i] = str[i];
	}
	_char_array[new_str_size] = '\0';
}

MyString& MyString::operator=(const char str){
	//TODO Alix
    _char_array[0]=str;
	_char_array[1]='\0';
}

MyString MyString::operator+(const MyString& str){
	//TODO Lucas
	MyString temp;
	int current_length = length();
	int target_length = current_length + str.length();
	int target_alloc = _alloc_size;
	do{
			target_alloc*=2;
	}while(target_alloc<target_length+1);
	temp.reserve(target_alloc);
	for(int i=0; i<current_length;i++){
		temp._char_array[i] = _char_array[i];
	}
	for(int i=current_length; i<target_length;i++){
		temp._char_array[i] = str._char_array[i-current_length];
	}
	temp._char_array[target_length] = '\0';
	return temp;
}

MyString MyString::operator+(const char * str){
	//TODO Alix
	MyString renv;
	int _length = length();
	int str_size = 0;
	while(str[str_size]!='\0') {
	    str_size++;
	}
	int new_size = _length + str_size ;
	if(_alloc_size < new_size + 1){
		int target_alloc = _alloc_size;
		do{
			target_alloc*=2;
		}while(target_alloc < new_size + 1);
		reserve(target_alloc);
	}
	for(int i=0; i<_length; i++){
		renv._char_array[i] = _char_array[i];
	}
	for (int j=_length; j<new_size; j++){
	    for(int g=0, g<str_size; g++){
	        renv._char_array[j] = str[g];
	    }
	}
	renv._char_array[new_size] = '\0';
	return renv;
}

MyString MyString::operator+(const char str){
	//TODO Léa
	if (_alloc_size < length()+1) {
		reserve(length()+1);
	}
	_char_array[length()] = str;
	_char_array[length()+1] = '\0';
}
