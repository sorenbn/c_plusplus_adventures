#include <iostream>

class String
{
private:
	char* buffer;
	unsigned int size;

public:
	String(const char* string)
	{
		size = strlen(string);
		buffer = new char[size + 1];
		// it's essentially the same as doing a for loop and copying over the characters manually
		memcpy(buffer, string, size);
		// adding the null-terminating character at the end
		buffer[size] = '\0';
	}

	// copy-constructor, deep-copy
	String(const String& other)
		: size(other.size)
	{
		buffer = new char[size + 1];
		memcpy(buffer, other.buffer, size + 1);
	}

	~String()
	{
		delete[] buffer;
	}

	const char* get_buffer() const
	{
		return buffer;
	}

	char& operator[](unsigned int index)
	{
		return buffer[index];
	}
};

// to_string() overload essentially
std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.get_buffer();
	return stream;
}

struct Vector2
{
	float x;
	float y;
};

void basics()
{
	int a = 2;
	// copies a into b, creating a copy. They get different memory addresses
	int b = a;

	// same thing for structs/classes
	Vector2 v1{ 2, 5 };
	Vector2 v2 = v1;

	// in this case, both pointers now point to the same memory address
	// so changing the value at the address affects both pointers, 
	// but you could still change or reassign v4 to point to something else
	// and v3 would still point to the original memory.
	Vector2* v3 = new Vector2();
	Vector2* v4 = v3;
}

// if this wasn't passed as a reference, a copy would actually be made via the copy-constructor, which is very unnessecary
// also const, so it can't be modified inside the function
void print_string(const String& string)
{
	std::cout << string << std::endl;
}

int main()
{
	basics();

	// when copying a class like this (when there is no copy-constructor), with an array (char*)
	// the copy will also point to the same char* array and thus, modify the value in both places
	// even tho they are seperate objects.
	// this will also crash, since the destructor will try to delete the same memory twice, when exiting scope (when there's no copy-constructor)
	// this is also known as a shallow-copy
	/*
		String str1("Hello");
		String str2 = str1;

		str2[2] = '5';

		std::cout << str1 << std::endl;
		std::cout << str2 << std::endl;
	*/

	// this now works as intended, since the copy-constructor is being used automatically, when assigning it to a new string.
	String str1("Hello");
	String str2 = str1;

	str2[2] = '5';

	print_string(str1);
	print_string(str2);

	return 0;
}