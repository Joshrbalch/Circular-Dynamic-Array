#include <iostream>
#include "CircularDynamicArray.cpp"

using namespace std;

int main() {

    CircularDynamicArray<int> myArray;

    myArray.addFront(1);
    myArray.addEnd(37);
    myArray.addFront(4);
    myArray.addEnd(89);

    myArray.print();

    // myArray.stableSort();

    // myArray.print();

    cout << "   " << myArray.QuickSelect(5) << endl;

    return 0;
}