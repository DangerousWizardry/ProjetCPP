#include <cctype>
#include <string>

class MyString
{
public:
	MyString();
	MyString(const MyString&);
	MyString(char *);
	~MyString();
	const char * c_str();
	size_t size();
	size_t length();
	size_t capacity();
	size_t max_size();
	void clear();
	bool empty();
	void resize(int new_size, char c);
	void reserve(size_t n);
	MyString& operator=(const std::string& str);
	MyString& operator=(const char * str);
	MyString& operator=(const char str);
	MyString& operator+(const std::string& str);
	MyString& operator+(const char * str);
	MyString& operator+(const char str);
protected:
	char * _char_array;
	int _max_size;
	int _alloc_size;
};