// starting with STL ---> standard template library
// allows to provide custom data type that the container can contain

// Vectors: dynamic arrays, auto sized unlike regular arrays. 
// to resize creates an expanded array ---> copies from old full array
// a heavy container and computanionally expensive if not optimized

#include <iostream>
#include <vector>

struct Vertex
{
    float x,y,z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << ',' << vertex.y << ',' << vertex.z;
    return stream; 
};

int main()
{
    // technically more optimal to store vertex objects directly rather than vertex pointers.
    // becuase mem is going to be inline, so essentially inline alloc is more optimmal as the members for each object will be on the same cache line.
    std::vector<Vertex> vertices;

    vertices.push_back({0,0,0});
    vertices.push_back({1,8,3});
    vertices.push_back({7,2,4});
    vertices.push_back({9,5,6});

    for (int i=0; i<vertices.size(); i++)
    {
        std::cout << vertices[i] << std::endl;
    }
    // can also use a for each loop
    // use the & for reference to avoid useless copies of the entire object.
    for(Vertex& v : vertices)
    {
        std::cout << v << std::endl;
    }

    vertices.clear(); // sets array size  back to 0 ---> remove all elements at once.
    return 0;
}
