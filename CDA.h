#include <iostream>
template <class myType>

class CircularDynamicArray {
    private:
    int capacityNum;
    int sizeNum;
    int front;
    int back;
    myType* array;

    public:

    bool resize();

    CircularDynamicArray();

    CircularDynamicArray(int s);

    ~CircularDynamicArray();

    myType& operator[](int i);

    void addEnd(myType v);

    void addFront(myType v);

    void delEnd();

    void delFront();

    int length();

    int capacity();

    void clear();

    myType QuickSelect(int k);

    myType WCSelect(int k);

    void stableSort();

    int linearSearch(myType e);

    int binSearch(myType e);

    void reverse();
};