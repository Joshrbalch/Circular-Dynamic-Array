#include <iostream>
#include "CircularDynamicArray.cpp"

using namespace std;

int main() {
    CircularDynamicArray<int> A(10);

    for(int i = 0; i < 5; i++) {
        A[i] = i;
    }

    A.addFront(1);
    A.reverse();

    for(int i = 0; i < A.length(); i++) {
        cout << A[i] << " ";
    }

    cout << endl;

    return 0;
}