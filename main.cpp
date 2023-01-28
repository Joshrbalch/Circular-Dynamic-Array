#include <iostream>
#include "CircularDynamicArray.cpp"

using namespace std;

int main() {

    CircularDynamicArray<int> myArray;

    myArray.addFront(11);
    myArray.addEnd(17);
    myArray.addEnd(19);
    myArray.addFront(21);
    // myArray.addFront(26);
    // myArray.addEnd(81);
    // myArray.addFront(78);

    myArray.print();



    return 0;
}