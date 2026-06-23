#include <iostream>
#include <memory>

class Entity
{
public:
	Entity()
	{
		std::cout << "Entity Created!" << std::endl;
	}

	~Entity()
	{
		std::cout << "Entity Destroyed!" << std::endl;
	}
	
	void print()
	{
		std::cout << "Printed!" << std::endl;
	}
};

// also kinda known as scoped pointers, meaning they will automatically destroy themselves once they go out of scope
// they are unique in the sense that you cannot copy a unique_ptr, because if the first one gets destroyed
// the 2nd one suddenly points to nothing.
// useful when you want a scoped pointer and it is the only pointer you need
// and also if the object you want to allocate is too big for the stack, and you want it to automatically call destroy
void unique_pointer()
{
	// create the unique_ptr like so, and once this function scope ends, the entity is destroyed automatically
	std::unique_ptr<Entity> entity = std::make_unique<Entity>();
	entity->print();
}

// they are essentially keeping track of a reference counter behind the scenes, and once this counter reaches 0
// the object gets destroyed. It's basically how a garbage collector works in C#.
// they have an overhead because of this.
void shared_pointer()
{
	std::shared_ptr<Entity> entity;

	// another scope
	{
		// create a new shared_ptr and assign the entity shared pointer outside the scope to it
		// and only when the shared_pointer() function scope dies, the shared_entity gets destroyed
		std::shared_ptr<Entity> shared_entity = std::make_shared<Entity>();
		
		// this increases the reference count
		entity = shared_entity;
	}

	// leaving the scope, which will then destroy the shared pointer
}

// they are essentially a pointer to something that _could_ be alive but maybe isn't.
// they can for example point to a shared_ptr but they will not increase the shared_ptr's reference count
// so once they shared_ptr dies, the weak pointer simply points to nothing anymore. nullable, in a way.
void weak_pointer()
{
	// nothing right now
	std::weak_ptr<Entity> entity;

	// another scope
	{
		// created a shared pointer to an entity
		std::shared_ptr<Entity> shared_entity = std::make_shared<Entity>();
		// assign the weak pointer to this new entity
		entity = shared_entity;

		// you have to convert the weak pointer into a shared pointer, in order to access its members and functions.....
		if (std::shared_ptr<Entity> ptr = entity.lock())
		{
			ptr->print();
		}
		
		// leaving the scope, shared_entity will be destroyed and the weak pointer is now pointing to nothing
	}
}

int main()
{
	unique_pointer();
	shared_pointer();
	weak_pointer();
}