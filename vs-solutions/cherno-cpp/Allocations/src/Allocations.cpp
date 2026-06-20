#include <iostream>
#include <string>

using string = std::string;

class Entity
{
private:
	string name;
	int age;
	
public:
	Entity()
	{
		name = "Unknown";
		age = 99;
	}

	Entity(const string& _name, int _age)
		: name(_name), age(_age)
	{

	}

	const string& get_name() const
	{
		return name;
	}

	void print_info()
	{
		std::cout << "Entity: " << name << ", Age: " << age << std::endl;
	}
};

int small_function()
{
	// will be destroyed once it leaves scope, because it's stack allocated
	Entity e("Test", 32);

	// do some stuff
	e.print_info();

	return 0;
}

void stack_allocations()
{
	// stack-allocated, calling the default constructor
	// if there is not contructor, memory is not initialized and will be garbage data 
	Entity entity1;
	entity1.print_info();

	// stack-allocated, calling the constructor matching the input given
	Entity entity2("Dumpy", 12);

	// could also be written like:
	/*Entity entity2 = Entity("Dumpy", 12);*/

	entity2.print_info();

	small_function();

	// can explicitly set a pointer to NULL, so that it can be read (like the if statement below) 
	Entity* entity_pointer = NULL;
	if (entity_pointer == NULL)
	{
		std::cout << "Pointer null" << std::endl;
	}

	// is essentially creating a new stack, inside this scope
	{
		Entity temp_entity("temp", 54);

		// at this moment, the entity_pointer is pointing to a valid entity
		entity_pointer = &temp_entity;
		entity_pointer->print_info();

		// but after we leave the scope, it's gonna get destroyed together with all other stack variables declared
	}

	// error, pointing to a destroyed object 
	/*entity_pointer->print_info();*/
}

Entity* create_entity(const string& name, int age = 69)
{
	// allocate it on the heap
	Entity* entity = new Entity(name, age);
	std::cout << "Created entity: " << entity->get_name() << std::endl;

	// return it to the caller, making it their responsibility to destroy it
	return entity;
}

void heap_allocations()
{
	// heap-allocated with the 'new' keyword, must be stored as a pointer
	// basically returns a location on the heap where this entity is stored
	// must be manually destroyed/free'd
	Entity* entity = new Entity("Heapy", 45);
	
	// you access members of the object via the arrow operator
	entity->print_info();
	// casting it to a de-reference does essentially the same thing, but arrow key is shorthand for it
	(*entity).get_name();

	// delete the pointer/entity, telling the OS the memory is available again
	delete entity;

	// create a new entity from a function
	Entity* new_entity = create_entity("Yolo", 70);
	new_entity->print_info();

	// manually destroy the entity, because the function is not responsible for that (and it would make it a useless function lol)
	delete new_entity;

	// allocate an array of 50 ints on the heap
	// notice it's almost the same as saying 'int* number = new int', as new always returns a pointer to the memory or the beginning of the memory, when it's an array
	int* array = new int[50]; // 200 bytes, 4 bytes per integer

	// delete the array with the delete[] keyword, specifically
	delete[] array;

	// 'new' is just an operator behind the scenes
	Entity* e1 = new Entity("Testyyy", 45);
	// it's essentially just calling malloc, with the size of the object, and returning it as a pointer.
	// the other difference being that 'new' will also invoke the constructor of the class.
	Entity* e2 = (Entity*)malloc(sizeof(Entity));

	// you can specifiy where in the memory this allocation is located.
	// in this case, it would override the memory of e1.
	Entity* e3 = new(e1) Entity("Testyyyy2", 456);
	 
	// delete is also an operator, which makes sure to invoke the destructor of the class
	delete e1;
	delete e2;
	delete e3;
}

int main()
{
	stack_allocations();
	heap_allocations();

	/*
		Some general thoughts:
		
		Is the object really really big, or do I need a lot of them? 
		Or maybe simply wanna control the lifetime of the object myself? 
		Then allocate on the heap.

		Otherwise, typically just allocating on the stack is the way to go.
	*/
}