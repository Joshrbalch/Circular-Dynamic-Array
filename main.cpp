#include <iostream>
#include "CircularDynamicArray.cpp"

using namespace std;

int main() {

    CircularDynamicArray<float> C(10);
	for (int i=0; i< C.length();i++) C[i] = i;
	C.print();
	// C => "0 1 2 3 4 5 6 7 8 9"
	C.delFront();
	C.print();
	// C => "1 2 3 4 5 6 7 8 9"
	C.delEnd();
	C.print();
	// C => "1 2 3 4 5 6 7 8"
	C.addEnd(100.0);
	C.print();
	// C => "1 2 3 4 5 6 7 8 100"
    C.delFront();
	C.addEnd(200.0);
	// C => "2 3 4 5 6 7 8 100 200"	

	C.addEnd(300.0);
	C.addEnd(400.0);
	// C => "2 3 4 5 6 7 8 100 200 300 400"	

    C.print();

    C.reverse();
    C.print();

    C.delFront(); C.delFront();C.delEnd();

    C.print();

    C.reverse();

    C.print();




    // myArray.stableSort();

    // myArray.print();

    // cout << "   " << myArray.QuickSelect(5) << endl;

    return 0;
}