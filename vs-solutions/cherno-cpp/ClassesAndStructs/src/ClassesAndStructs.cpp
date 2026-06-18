#include <iostream>

#define LOG(x) std::cout << x << std::endl

// everything is private by default, mark public for exposing
class Player
{
public:
    float x;
    float y;
    float speed;

    // constructor
    Player()
    {
        x = 0;
        y = 0;
        speed = 1;
    }

    Player(float _x, float _y, float _speed)
    {
        x = _x;
        y = _y;
        speed = _speed;
    }

    void Move(int dx, int dy) 
    {
        x += dx * speed;
        y += dy * speed;
    }
};

// everything is public by default
struct Enemy
{
    float x;
    float y;
    float speed;

    void Move(int dx, int dy)
    {
        x += dx * speed;
        y += dy * speed;
    }
};

struct Vec2f
{ 
    float x = 0.0f;
    float y = 0.0f;

    void Add(const Vec2f& other)
    {
        x += other.x;
        y += other.y;
    }
};

// static utility-type logger that doesn't allow for construction of a Log class.
class Log
{
private:
    Log()
    {

    }
public:
    static void Write(const char* message)
    {
        std::cout << message << std::endl;
    }
};

int main()
{
    Player player{};
    player.Move(2, 4);

    LOG(player.x);
    LOG(player.y);

    Player player2(1.0, 2.0, 3.0);

    LOG(player2.x);
    LOG(player2.y);

    Enemy enemy{};
    enemy.speed = 5.0f;
    enemy.Move(5, 8);

    LOG(enemy.x);
    LOG(enemy.y);

    Vec2f v1{};
    v1.x = 2.0f;
    v1.y = 2.0f;

    LOG(v1.x);
    LOG(v1.y);

    Vec2f v2{};
    v2.x = 1.0f;
    v2.y = 1.0f;

    v2.Add(v1);

    LOG(v2.x);
    LOG(v2.y);

    Log::Write("Static log message");
}