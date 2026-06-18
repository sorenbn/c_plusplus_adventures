#include <iostream>
#include <array>

class Entity
{
public:
	static const int SIZE = 4;
	// stack allocated, contigous allocated in memory.
	int numbers_stack[SIZE];

	// heap allocated number array makes the memory 'scattered'. 
	// now the entity lives one place, and it's array lives in some completely other place in memory, making it not contigous memory.
	int* numbers_heap = new int[SIZE];

	Entity()
	{
		for (int i = 0; i < SIZE; i++)
		{
			numbers_stack[i] = (i + 1);
		}

		for (int i = 0; i < SIZE; i++)
		{
			numbers_heap[i] = (i + 1);
		}
	}

	void print()
	{
		std::cout << "I'm an entity" << std::endl;
	}
};

void raw_array()
{
	// an array is basically a pointer to the beginning of the array of data.
	int example_array[5];
	example_array[0] = 2;
	example_array[4] = 5;

	// print the element inside the array
	std::cout << example_array[0] << std::endl;

	// simply print the address of the array
	std::cout << example_array << std::endl;

	for (int i = 0; i < 5; i++)
	{
		example_array[i] = (i + 1) * 100;
		std::cout << example_array[i] << std::endl;
	}

	// calculate the total amount of bytes stored
	int size_in_bytes = sizeof(example_array);
	std::cout << size_in_bytes << std::endl;

	// calculate the count of elements in the array itself
	// only works with stack allocated arrays, and is not guaranteed to work when array is passed as a pointer to a function
	// easier to just keep track of the size yourself (see Entity class)
	int count = size_in_bytes / sizeof(int);
	std::cout << count << std::endl;

	// better way of writing the same thing.
	size_t count_type_indifferent = sizeof(example_array) / sizeof(example_array[0]);
	
	// using the standard library
	size_t std_count = std::size(example_array);

	// it's the same, because array is already a pointer
	int* array_pointer = example_array;

	example_array[2] = 5;
	// this is the same as above, since it's basically offsetting the pointer, from the start position (pointer arithmetic).
	// when you add + 2, it mutliplies by the size of the type (4 bytes in this case)
	// dereference the pointer to actually set the value
	*(array_pointer + 2) = 6;

	// allocated on the heap, must destroy manually
	int* another_array = new int[5];

	for (int i = 0; i < 5; i++)
	{
		another_array[i] = i;
	}

	delete[] another_array;

	Entity e = {};
	e.print();
}

void std_array()
{
	std::array<int, 5> std_array;

	for (size_t i = 0; i < std_array.size(); i++)
	{
		std_array[i] = i + 1;
	}
}

int main()
{
	raw_array();
	std_array();

	return 0;
}