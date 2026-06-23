#include <iostream>
#include <vector>

struct Vertex
{
	float x;
	float y;
	float z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << "(" << vertex.x << ", " << vertex.y << ", " << vertex.z << ")";
	return stream;
}

void print_dynamic_array(const std::vector<Vertex>& vertices)
{
	for (const Vertex& v : vertices)
	{
		std::cout << v << std::endl;
	}
}

int main()
{
	// simple static array, tied to fixed size
	Vertex vertices[5];
	
	// dynamic array of vertices (like List<T> in C#)
	std::vector<Vertex> dynamic_vertices;

	// add new elements to the dynamic array
	dynamic_vertices.push_back({ 1, 2, 3 });
	dynamic_vertices.push_back({ 4, 5, 6 });
	dynamic_vertices.push_back({ 7, 8, 9 });

	// for loop
	for (int i = 0; i < dynamic_vertices.size(); i++)
	{
		std::cout << dynamic_vertices[i] << std::endl;
	}

	// removes the 2nd element of the array (index = 1)
	dynamic_vertices.erase(dynamic_vertices.begin() + 1);

	// for-each loop, make sure to mark it as reference to avoid copying for each iteration
	for (Vertex& v : dynamic_vertices)
	{
		std::cout << v << std::endl;
	}

	// clear all elements
	dynamic_vertices.clear();
	dynamic_vertices.push_back({ 10, 11, 12 });

	// make sure to pass the dynamic array as a reference to avoid copying the data
	print_dynamic_array(dynamic_vertices);

	return 0;
}