#include <cctype>
#include <string>
#include <iostream>
#include <stdexcept>

class MyString
{
public:
	MyString();
	MyString(const MyString&);
	MyString(char *);
	~MyString();
	const char * c_str();
	size_t size() const;
	size_t length() const;
	size_t capacity();
	size_t max_size();
	void clear();
	bool empty();
	void resize(int new_size, char c);
	void reserve(size_t n);
	MyString& operator=(const MyString&);
	MyString& operator=(const char *);
	MyString& operator=(const char);
	MyString operator+(const MyString&);
	MyString operator+(const char *);
	MyString operator+(const char);
	
protected:
	const static int _max_size;
	int _alloc_size;
	char * _char_array;
};