#include <iostream>
#include "CircularDynamicArray.cpp"

using namespace std;

int main() {

    CircularDynamicArray<int> myArray;

    for(int i = 0; i < 100; i++) {
        myArray.addEnd(i);
    }

    myArray.print();

    return 0;
}