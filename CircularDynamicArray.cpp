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

    CircularDynamicArray(const CircularDynamicArray& other) {
        std::cout << "COPY" << std::endl;
        int arrayCap = other.capacityNum;
        array = new myType[capacityNum];

        for(int i = 0, j = front; i < sizeNum; i++) {
            array[i] = other.array[j];
            j = (j + 1) % capacityNum;
        }
        
        capacityNum = other.capacityNum;
        sizeNum = other.sizeNum;
        front = other.front;
        back = other.back;
        empty = other.empty;
    }

    CircularDynamicArray& operator=(const CircularDynamicArray& other) {
        std::cout << "EQUALS" << std::endl;
        if(&other != this) {
            CircularDynamicArray temp(other);
            std::swap(array, temp.array);
            std::swap(capacityNum, temp.capacityNum);
        }
    }

    myType& operator[](int i) {

    }

    bool resize() {
        capacityNum *= 2;
        return true;
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
            return;
        }

        front = (front - 1 + capacityNum) % capacityNum;
        array[front] = v;
        sizeNum++;
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
        std::cout << "NUMBER OF ELEMENTS: " << sizeNum << std::endl;
        int j = front;

        for(int i = 0; i < sizeNum; i++) {
            if(j == capacityNum) {
                j = 0;
            }

            std::cout << array[j] << std::endl;

            j++;
        }
    }

    void increaseSize() {
        capacityNum *= 2;

        myType* temp = new myType[capacityNum];

        int i = front;
        int j = 0;

        while (i != back) {
            temp[j] = array[i];
            i = (i + 1) % sizeNum;
            j++;
        }
        
        temp[j] = array[i];

        // std::cout << "TEMP:" << std::endl;

        // for(int i = 0; i < capacityNum; i++) {
        //     std::cout << temp[i] << std::endl;
        // }

        front = 0;
        back = sizeNum - 1;

        delete[] array;

        array = temp;
    }
};