#include <iostream>
using namespace std;
#include "CircularDynamicArray.cpp"
// void foo(CircularDynamicArray<int> x) {
//  for (int i=0; i<x.length()/2; i++)
//      x[i] = x[x.length()/2+i];
//  // X => "6 7 8 9 10 15 19 6 7 8 9 10 15 19 11"
//  for (int i=0; i< x.length();i++) cout << x[i] << " ";  cout << endl;
// }
int main() {
    CircularDynamicArray<float> C(10);
    for (int i=0; i< C.length();i++) C[i] = i;
    // C => "0 1 2 3 4 5 6 7 8 9"
    C.delFront();
    
    // C => "1 2 3 4 5 6 7 8 9"
    C.delEnd();
    
    // C => "1 2 3 4 5 6 7 8"
    C.addEnd(9.0);
    // C => "1 2 3 4 5 6 7 8 100"
    C.delFront();
    C.addEnd(10.0);
    // C => "2 3 4 5 6 7 8 100 200"
    C.addEnd(11.0);
    C.addEnd(12.0);
    C.addEnd(13.0);
    C.addEnd(14.0);
    C.addEnd(15.0);
    C.addEnd(16.0);
    C.addEnd(17.0);
    C.addEnd(18.0);
    C.addEnd(19.0);
    C.addEnd(20.0);
    C.addEnd(21.0);
    C.addEnd(22.0);
    for (int i=0; i< C.length();i++) cout << C[i] << " ";  cout << endl;
    
    C.addFront(1.0);
	C.addFront(-1);
	C.addFront(-2);


    for (int i=0; i< C.length();i++) cout << C[i] << " ";  cout << endl;
    C.reverse();
    for (int i=0; i< C.length();i++) cout << C[i] << " ";  cout << endl;
    C.addFront(23.0);
    for (int i=0; i< C.length();i++) cout << C[i] << " ";  cout << endl;

    cout << C.getBack() << endl;
    cout << C.length() << endl;
}