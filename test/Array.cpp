
#include <iostream>
#include <../include/dsa/DataStructure/Array.hpp>

int main()
{
    dsa::Array<int, 8> array;

    array[0] = 1; // ok
    array.at(1) = 1; // ok
    // array.at(array.size()) = 1; // this throws an out of range exception
    // arra[arra.size()] = 1; // this does not throws and exception (unsafe)

    for (size_t i = 0; i < array.size(); i++)
        array[i] = i * 2;

    // not implemented yet
    //for (auto &&i : array)
    //    array[i] = i * 2;

    for (size_t i = 0; i < array.size(); i++)
        std::cout << i << "\n";

    return 0;
}
