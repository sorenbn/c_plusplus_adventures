#include <iostream>

class Entity
{
public:
	void print() const
	{
		std::cout << "Hello!" << std::endl;
	}
};

int main()
{
	// actual entity
	Entity e;
	e.print();

	// pointer to the entity
	Entity* e_ptr = &e;
	
	// the same thing, essentially. Arrow operator is just easier and less clunky
	(*e_ptr).print();
	e_ptr->print();

	// reference to the entity, which avoids it all together because it simply dereferences it into a variable
	Entity& e_reference = *e_ptr;
	e_reference.print();

	return 0;
}