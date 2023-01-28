#include <iostream>
// #include "CDA.h"
template <class myType>

class CircularDynamicArray {
    private:
    int capacityNum;
    int sizeNum;
    int front;
    int back;
    bool empty;
    myType* array;

    public:

    CircularDynamicArray() {
    capacityNum = 2;
    sizeNum = 0;
    front = 0;
    back = 0;
    empty = 1;
    array = new myType[capacityNum];
    }

    bool resize() {
        capacityNum *= 2;
        return true;
    }

    CircularDynamicArray(int s) {
        capacityNum = s;
        sizeNum = s;
        front = 0;
        back = 1;
        empty = 1;
        array = new myType[capacityNum];
    }

    ~CircularDynamicArray() {
        delete [] array;
        array = nullptr;
    }

    myType& operator[](int i) {

    }

    void addEnd(myType v) {
        if(empty == 1) {
            empty = 0;
            array[front] = v;
            sizeNum++;
        }

        else {
            if(back == capacityNum) {
                if(sizeNum == capacityNum) {
                    increaseSize();
                    back++;
                    array[back] = v;
                    sizeNum++;
                }

                else {
                    back = 0;
                    array[back] = v;
                    sizeNum++;
                }
            }

            else {
                back += 1;
                array[back] = v;
                sizeNum++;
            }
        }
    }

    void addFront(myType v) {
        if(sizeNum == capacityNum) {
            increaseSize();
        }
        
        if(empty == 1) {
            empty = 0;
            array[front] = v;
            sizeNum++;
        }

        else {
            if(front == 0) {
                front = capacityNum - 1;
                array[front] = v;
            }

            else {
                front -= 1;
                array[front] = v;
            }

            sizeNum++;
        }
    }

    void delEnd() {

    }

    void delFront() {

    }

    int length() {
        return sizeNum;
    }

    int capacity() {
        return capacityNum;
    }

    void clear() {

    }

    myType QuickSelect(int k) {

    }

    myType WCSelect(int k) {

    }

    void stableSort() {

    }

    int linearSearch(myType e) {
        return 0;
    }

    int binSearch(myType e) {
        return 0;
    }

    void reverse() {

    }

    bool isEmpty() {
        if(empty == 1) {
            return true;
        }

        else {
            return false;
        }
    }

    void print() {
        int i = front;

        while(i != back) {
            if(i == capacityNum) {
                i = 0;
            }

            std::cout << array[i] << std::endl;
            i++;
        }
    }

    void increaseSize() {
        capacityNum *= 2;

        myType* temp = new myType[capacityNum];

        for(int i = 0, j = front; i < sizeNum; i++) {
            temp[i] = array[j];
            j = (j + 1) % sizeNum;
        }

        front = 0;
        back = sizeNum - 1;

        delete[] array;

        array = temp;
    }
};