#include <iostream>
#include <string>

using string = std::string;

class Entity
{
private:
    string name;
    int age;

public:
    Entity(const string& _name)
        : name(_name), age(-1)
    {

    }

    Entity(int _age)
        : name("Unknown"), age(_age)
    {

    }

    const string& get_name() const
    {
        return name;
    }

    int get_age() const
    {
        return age;
    }
};

class Enemy
{
private:
    int hp;

public:
    explicit Enemy(int _hp)
        : hp(_hp)
    {

    }
};

void print_entity(const Entity& entity)
{
    std::cout << entity.get_name() << std::endl;
    std::cout << entity.get_age() << std::endl;
}

void implicit_casting()
{
    // implicit conversions because c++ can use the constructors from the Entity class to convert it into a string/int..
    // insane behaviour, I know.
    Entity a = string("Dumpy");
    Entity b = 22;

    // same for passing it as a function argument
    print_entity(string("Dummmmpyyy"));
    print_entity(28);
}

void explicit_casting()
{
    // illegal to cast it to an integer via the constructor
    //Enemy enemy = 22;

    // must explicitly be called by the constructor
    Enemy enemy = Enemy(22);
}

int main()
{
    implicit_casting();
    explicit_casting();
}

