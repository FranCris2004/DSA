
#include <iostream>
#include <dsa/DataStructure/Array.hpp>

int main()
{
    using namespace std;
    using namespace dsa;

    Array<int, 8> array;

    array[0] = 1;    // ok
    array.at(1) = 1; // ok
    /*
    array.at(array.size()) = 1; // this throws an out of range exception
    array[array.size()] = 1;    // this does not throws and exception (unsafe)
    */

    for (size_t i = 0; i < array.size(); i++)
        array[i] = i * 2;

    // not implemented yet
    /*
    for (auto &&i : array)
        array[i] = i * 2;
    */

    for (size_t i = 0; i < array.size(); i++)
        cout << i << "\n";

    // 0 sized array
    /*
    Array<int, 0> arr0;
    cout << arr0[0] << "\n";
    arr0[0] = 1;
    cout << arr0[0] << "\n";
    */

    return 0;
}
