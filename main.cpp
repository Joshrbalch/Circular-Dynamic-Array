#include <iostream>
#include "CDA.cpp"

using namespace std;

int main() {

    CircularDynamicArray<int> myArray;

    myArray.addFront(1);
    myArray.addFront(2);
    myArray.addFront(3);

    myArray.print();

    return 0;
}