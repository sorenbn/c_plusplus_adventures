#include <iostream>

// simple singleton example
class EntityManager
{
public:
	static EntityManager& get()
	{
		// statically declare an instance, which is only initialized the first time this function gets called, and persists throughout the app lifecycle
		static EntityManager instance;
		return instance;
	}

	void print_hello()
	{
		std::cout << "Hello from a singleton entity manager" << std::endl;
	}
};

// if 'some_int' inside static.cpp was not marked static, the linker would crash because of duplicate defines
int some_int = 5;

// extern can specify these variables and functions exists somewhere in this application and the linker will hook them up.
// extern also only declares, it does not allocate
extern int external_variable;
extern void external_function();

// static inside functions keeps the lifetime of the variable, across multiple calls to the function (keeping state)
void increment()
{
	// only initialized the first time
	static int counter = 0;

	counter++;
	std::cout << counter << std::endl;
}

struct Entity
{
	int x;
	int y;

	// static variable that's "global" for all instances of Entity. Shared, pointing to the same memory.
	static int count;

	// const here basically means it will not change any of the member variables of this entity, inside this function.
	void print() const
	{
		std::cout << x << ", " << y << ", count: " << count << std::endl;
	}

	static void print(const Entity& entity)
	{
		std::cout << entity.x << ", " << entity.y << ", count: " << count << std::endl;
	}
};

// declare the static variable of entity here so the linker can find a location for it to store the static value.
int Entity::count;

int main()
{
	std::cout << some_int << std::endl;

	std::cout << external_variable << std::endl;
	external_function();

	for (int i = 0; i < 5; i++)
	{
		increment();
	}

	Entity e1 = {};
	e1.x = 2;
	e1.y = 3;
	e1.count = 1;

	Entity e2 = 
	{
		5, 
		8
	};
	e2.count = 5;

	e1.print();
	e2.print();

	// it's essentially the same as e1.count since it's a "global" variable inside all entity instances
	Entity::count = 10;
	e1.print();

	Entity::print(e2);

	EntityManager::get().print_hello();
}