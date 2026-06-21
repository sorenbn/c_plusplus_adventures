#include <iostream>

struct Vec2f
{
	float x;
	float y;

	Vec2f(float _x, float _y)
		: x(_x), y(_y)
	{
	}

	Vec2f add(const Vec2f& other) const
	{
		return Vec2f(x + other.x, y + other.y);
	}

	Vec2f operator+(const const Vec2f& other) const
	{
		return Vec2f(x + other.x, y + other.y);
	}

	Vec2f multiply(float scale) const
	{
		return Vec2f(x * scale, y * scale);
	}

	Vec2f operator*(float scale) const
	{
		return Vec2f(x * scale, y * scale);
	}

	bool equals(const Vec2f& other) const
	{
		return x == other.x && y == other.y;
	}

	bool operator==(const Vec2f& other) const
	{
		return x == other.x && y == other.y;
	}

	bool operator!=(const Vec2f & other) const
	{
		return !(*this == other);
		
		// same as above
		//return !(this->equals(other));
	}
};

// override the << operator for the stream, to easily print out Vec2f (like .ToString() in C#)
std::ostream& operator<<(std::ostream& stream, const Vec2f& other)
{
	stream << other.x << ", " << other.y;
	return stream;
}

int main()
{
	Vec2f position(2, 2);
	Vec2f speed(0.5f, 0.5f);
	float speed_multipler = 2.0f;

	// without operator overloading, this is starting to get hard to read
	Vec2f result = position.add(speed.multiply(speed_multipler));
	
	std::cout << result << std::endl;

	// using operators, makes it look a lot more like traditional math 
	Vec2f result2 = position + speed * speed_multipler;
	std::cout << result2 << std::endl;

	// no operator overloading
	if (result.equals(result2))
	{
		std::cout << "Equals!" << std::endl;
	}

	// with operator overloading
	if (result == result2)
	{
		std::cout << "Equals!" << std::endl;
	}
}