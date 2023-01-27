#include <iostream>

template <class myType>

class CircularDynamicArray {
    private:
    int capacity;
    int size;
    int front;
    int back;
    public:

    myType* array;

    bool resize();

    CircularDynamicArray() {
        array = new myType();
        capacity = 2;
        size = 0;
        front = 0;
        back = 0;
    }

    CircularDynamicArray(int s) {
        array = new myType();
        capacity = s;
        size = s;
        front = 0;
        back = 0;
    }

    ~CircularDynamicArray();

    myType& operator[](int i);

    void addEnd(myType v);

    void addFront(myType v);

    void delEnd();

    void delFront();

    int length();

    int capacity();

    void clear();

    mytype QuickSelect(int k);

    myType WCSelect(int k);

    void stableSort();

    int linearSearch(myType e);

    int binSearch(myType e);

    void reverse();
};