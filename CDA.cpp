#include <iostream>
#include "CDA.h"

template <class myType>

CircularDynamicArray<myType>::CircularDynamicArray() {
    capacityNum = 2;
    sizeNum = 0;
    front = -1;
    back = -1;
    array = new myType[capacityNum];
}

template <class myType>

bool CircularDynamicArray<myType>::resize() {
    capacityNum *= 2;
    return true;
}

template <class myType>

CircularDynamicArray<myType>::CircularDynamicArray(int s) {
    capacityNum = s;
    sizeNum = s;
    front = -1;
    back = -1;
    array = new myType[capacityNum];
}

template <class myType>

CircularDynamicArray<myType>::~CircularDynamicArray() {
    delete [] array;
    array = nullptr;
}

template <class myType>

myType& CircularDynamicArray<myType>::operator[](int i) {

}

template <class myType>

void CircularDynamicArray<myType>::addEnd(myType v) {

}

template <class myType>

void CircularDynamicArray<myType>::addFront(myType v) {

}

template <class myType>

void CircularDynamicArray<myType>::delEnd() {

}

template <class myType>

void CircularDynamicArray<myType>::delFront() {

}

template <class myType>

int CircularDynamicArray<myType>::length() {
    return sizeNum;
}

template <class myType>

int CircularDynamicArray<myType>::capacity() {
    return capacityNum;
}

template <class myType>

void CircularDynamicArray<myType>::clear() {

}

template <class myType>

myType CircularDynamicArray<myType>::QuickSelect(int k) {

}

template <class myType>

myType CircularDynamicArray<myType>::WCSelect(int k) {

}

template <class myType>

void CircularDynamicArray<myType>::stableSort() {

}

template <class myType>

int CircularDynamicArray<myType>::linearSearch(myType e) {
    return 0;
}

template <class myType>

int CircularDynamicArray<myType>::binSearch(myType e) {
    return 0;
}

template <class myType>

void CircularDynamicArray<myType>::reverse() {

}
