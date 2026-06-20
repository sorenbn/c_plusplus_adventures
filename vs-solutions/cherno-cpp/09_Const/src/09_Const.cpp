#include <iostream>
#include "utils.h"

class Entity 
{
private:
	int x;
	int y;

public:
	int get_x() const
	{
		return x;
	}

	int get_y()
	{ 
		return y;
	}

	void set_x(int _x)
	{
		x = _x;
	}

	void set_y(int _y)
	{
		y = _y;
	}
};

void print_entity(const Entity& e)
{
	std::cout << e.get_x() << std::endl;

	// not allowed to call get_y since it's not marked const.. insane.
	//std::cout << e.get_y() << std::endl;
}

void const_pointers()
{
	// constant value, cannot change after initialization
	const int MAX_AGE = 90;

	int number = 12;

	// pointer pointing to a const value, cannot change the VALUE at the pointer (but still the pointer itself)
	// think it like reading it backwards: ptr_const is a pointer to an int that is const
	const int* ptr_const = &number;

	// illegal
	//*ptr_const = 45;

	// can still dereference and read the value
	std::cout << *ptr_const << std::endl;

	// const pointer where the value can be changed, but the pointer itself cannot
	// think it like reading it backwards: const_ptr is a const pointer to an int
	int* const const_ptr = &number;

	// illegal
	//const_ptr = &number;

	// but valid to assign a value to the value it points to 
	*const_ptr = 45;

	// can neither change the value or the pointer itself
	const int* const fixed_pointer = &number;

}

int main()
{
	const_pointers();

	int x = 8;
	// pass x into lambda by value (a copy)
	auto lambda_by_value = [=]() mutable
		{
			x++;
			std::cout << x << std::endl;
		};

	lambda_by_value();

	// pass x into lambda by reference 
	auto lambda_by_reference = [&x]()
		{
			x++;
			std::cout << x << std::endl;
		};

	lambda_by_reference();
	
	assert(false, "Nub");

	std::cin.get();
}