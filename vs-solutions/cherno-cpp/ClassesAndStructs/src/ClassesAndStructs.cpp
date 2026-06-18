#include <iostream>

#define LOG(x) std::cout << x << std::endl

// everything is private by default, mark public for exposing
class Player
{
public:
    int x;
    int y;
    float speed;

    Player()
    {
        x = 0;
        y = 0;
        speed = 1;
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
    int x;
    int y;
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

int main()
{
    Player player{};
    player.Move(2, 4);

    LOG(player.x);
    LOG(player.y);

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
}