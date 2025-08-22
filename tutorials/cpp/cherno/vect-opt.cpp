// optimizing the vector container.
// to optimize usage of vectors ---> try to optimize the underlying copy operation that happens on a push back call when the vector is at max capacity
// to understand the conditions for the copy operation to occur ---> we can track copies using a copy constructor


#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
    float x,y,z;

    // default constructor
    Vertex(float x, float y, float z) : x(x), y(y), z(z) {}

    // copy constructor
    Vertex(const Vertex& vertex) : x(vertex.x), y(vertex.y), z(vertex.z)
    {
        std::cout << "Copied" << std::endl;
    }


};


int main()
{
    std::vector<Vertex> vertices;
    // 3 pushbacks result in 6 copies
    vertices.push_back({1,1,1});
    vertices.push_back({0,2,6});
    vertices.push_back({0,0,0});

    // first copy ---> when 1 vertex pushed
    // when we construct the Vertex --> we construct in the current stack frame for the main function, then we copy into the vector mem space.
    // we can optimize this by constructiing the vertex in place in actual memory alloc to the vector instead of alloc in the main function stack frame

    // 2 more copies done when the next Vertex obj made  ---> 1 copy from stack to vector mem space and the second copy is post expansion to new increased capacity

    // instead of expanding using copy multiple times make enough memory for 3 elements from the begining since we know num of elements.
    // Optimization 2 => keep a base capacity.

    // applying optimization 2 ---> only 3 copies for main to vector mem space
    std::cout << std::endl;
    std::vector<Vertex> vertices_opt2;
    vertices_opt2.reserve(3); // reserve space for 3 push backs
    vertices_opt2.push_back({1,1,1});
    vertices_opt2.push_back({0,2,6});
    vertices_opt2.push_back({0,0,0});

    // optimization 1 ---> use emplace_back instead of push back to create the vertex in the Vector mem space directly
    std::cout << std::endl;
    std::vector<Vertex> vertices_opt1;
    vertices_opt1.reserve(3); // reserve space for 3 push backs
    vertices_opt1.emplace_back(1,1,1);
    vertices_opt1.emplace_back(0,2,6);
    vertices_opt1.emplace_back(0,0,0);

    return 0;
}