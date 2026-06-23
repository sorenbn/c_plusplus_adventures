#include <iostream>

class Printable
{
public:
    // initializing to 0 means abstract function
    virtual const char* get_class_name() = 0;
};

class Entity : public Printable
{
public:
    float x = 0.0f;
    float y = 0.0f;

    void move(float delta_x, float delta_y)
    {
        x += delta_x;
        y += delta_y;
    }

    void print_info()
    {
        std::cout << "Entity position: (" << x << ", " << y << ")" << std::endl;
    }

    virtual const char* get_name()
    {
        return "Entity";
    }

    // basically an abstract function like C#
    virtual const char* get_last_name() = 0;

    // Inherited via Printable
    const char* get_class_name() override
    {
        return "Entity";
    }
};

class Player : public Entity
{
private:
    const char* name;

public:
    Player(const char* name) 
        : name(name)
    {

    }

    void print_name()
    {
        std::cout << "Entity name: " << name << std::endl;
    }

    const char* get_name() override
    {
        return name;
    }

    const char* get_last_name() override
    {
        return "Dumpyson";
    }

    // Inherited via Printable
    const char* get_class_name() override
    {
        return "Player";
    }
};

void print(Printable* entity)
{
    std::cout << entity->get_class_name() << std::endl;
}

int main()
{
    Player* player = new Player("Dumpy");
    player->x = 2;
    player->y = 2;

    player->print_info();
    player->print_name();
    player->move(5, 5);
    player->print_info();

    std::cout << sizeof(Entity) << std::endl;
    std::cout << sizeof(Player) << std::endl;

    print(player);
    
    std::cout << player->get_name() << " " << player->get_last_name() << std::endl;
}