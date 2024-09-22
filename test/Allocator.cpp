
#include <iostream>
#include <string>
#include <dsa/DataStructure/Allocator.hpp>

using namespace std;
using namespace dsa;

class Object
{
public:
    Object() { cout << "Constructor\n"; }
    ~Object() { cout << "Destructor\n"; }
};

int main()
{
    dsa::Allocator<int> *int_alloc = new dsa::DefaultAllocator<int>();

    int *const ptr = int_alloc->allocate(3); // allocates memory for 3 ints

    for (size_t i = 0; i < 3; i++)
        ptr[i] = i;

    for (size_t i = 0; i < 3; i++)
        cout << ptr[i] << "\n";

    int_alloc->deallocate(ptr);

    delete int_alloc;

    dsa::Allocator<Object> *object_alloc = new dsa::DefaultAllocator<Object>();

    Object *object = object_alloc->allocate(1); // allocates unitialized memory for 1 Object
    new (object) Object();                      // initialize the memory (calls the constructor)
    object->~Object();                          // calls the destructor
    object_alloc->deallocate(object);           // deallocates the memory

    delete object_alloc;

    return 0;
}
