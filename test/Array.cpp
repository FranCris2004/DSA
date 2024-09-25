
#include <iostream>
#include <dsa/DataStructure/Array.hpp>

using namespace std;
using namespace dsa;

class Object
{
public:
    Object() { cout << "constructor\n"; }
    ~Object() { cout << "destructor\n"; }
};

int main()
{
    Array<int, 3> array;

    array[0] = 1;    // ok
    array.at(1) = 1; // ok
    // array.at(array.size()) = 1; // this throws an out of range exception
    // array[array.size()] = 1;    // this does not throws and exception (unsafe)

    for (size_t i = 0; i < array.size(); i++)
        array[i] = i * 2;

    // not implemented yet
    /*
    for (auto &&i : array)
        array[i] = i * 2;
    */

    cout << "array: {";
    for (size_t i = 0; i < array.size(); i++)
        cout << i << ",";
    cout << "}\n";

    // zero-sized array
    Array<int, 0> zero_sized;

    // zero_sized[0] = 1; // abort the execution
    cout << zero_sized.size() << "\n";
    cout << zero_sized.data() << "\n";

    // object array

    Array<Object, 3> object_array;


    return 0;
}
