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

    void decreaseSize() {
        capacityNum /= 2;

        myType* temp = new myType[capacityNum];

        int i = front;
        int j = 0;

        while (i != back) {
            temp[j] = array[i];
            i = (i + 1) % sizeNum;
            j++;
        }
        
        temp[j] = array[i];

        front = 0;
        back = sizeNum - 1;

        delete[] array;

        array = temp;
    }

    int partition(myType arr[], int l, int r) {
        myType x = arr[r], i = l;
        myType temp{};

        for (int j = l; j <= r - 1; j++) {
            if (arr[j] <= x) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
            }
        }

        temp = arr[i];
        arr[i] = arr[r];
        arr[r] = temp;
        return i;
    }

    void mergeSort(myType array[], int const begin, int const end)
    {
        if (begin >= end) {
            return; // Returns recursively
        }

        auto mid = begin + (end - begin) / 2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid + 1, end);
        merge(array, begin, mid, end);
    }

    void merge(myType array[], int const left, int const mid, int const right) {

        myType const subArrayOne = mid - left + 1;
        myType const subArrayTwo = right - mid;
    
        // Create temp arrays
        myType *leftArray = new myType[subArrayOne], *rightArray = new myType[subArrayTwo];
    
        // Copy data to temp arrays leftArray[] and rightArray[]
        for (auto i = 0; i < subArrayOne; i++) {
            leftArray[i] = array[left + i];
        }

        for (auto j = 0; j < subArrayTwo; j++) {
            rightArray[j] = array[mid + 1 + j];
        }
    
        auto indexOfSubArrayOne = 0, // Initial index of first sub-array
            indexOfSubArrayTwo
            = 0; // Initial index of second sub-array

        int indexOfMergedArray = left; // Initial index of merged array
    
        // Merge the temp arrays back into array[left..right]
        while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
            if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }

            else {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }

            indexOfMergedArray++;
        }

        // Copy the remaining elements of
        // left[], if there are any
        while (indexOfSubArrayOne < subArrayOne) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            indexOfMergedArray++;
        }

        // Copy the remaining elements of
        // right[], if there are any
        while (indexOfSubArrayTwo < subArrayTwo) {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfMergedArray++;
        }

        delete[] leftArray;
        delete[] rightArray;
    }

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

        return *this;
    }

    myType& operator[](int i) {
        return array[i];
    }

    void addEnd(myType v) {
        if(sizeNum == capacityNum) {
            increaseSize();
        }

        if(empty == 1) {
            empty = 0;
            array[front] = v;
            sizeNum++;
            return;
        }

        back = (back + 1) % capacityNum;;
        array[back] = v;
        sizeNum++;
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
        if(front == back) {
            empty = true;
            sizeNum--;
            return;
        }

        back = (back - 1 + capacityNum) % capacityNum;
        sizeNum--;

        if(sizeNum <= (capacityNum / 4)) {
            decreaseSize();
        }
    }

    void delFront() {
        if(empty == 1) {
            return;
        }

        if(front == back) {
            empty = true;
            sizeNum--;
            return;
        }

        front = (front + 1) % capacityNum;
        sizeNum--;

        if(sizeNum <= (capacityNum / 4)) {
            decreaseSize();
        }
    }

    int length() {
        return sizeNum;
    }

    int capacity() {
        return capacityNum;
    }

    void clear() {
        delete[] array;

        array = new myType();
        capacityNum = 2;
        sizeNum = 0;
    }

    myType QuickSelect(int k) {
        return kthSmallest(array, 0, sizeNum - 1, k);
    }

    myType kthSmallest(myType arr[], int l, int r, int k) {
        // If k is smaller than number of 
        // elements in array
        if (k > 0 && k <= r - l + 1) {
    
            // Partition the array around last 
            // element and get position of pivot 
            // element in sorted array
            int index = partition(arr, l, r);
    
            // If position is same as k
            if (index - l == k - 1) {
                return arr[index];
            }

            // If position is more, recur 
            // for left subarray
            if (index - l > k - 1) { 
                return kthSmallest(arr, l, index - 1, k);
            }

            // Else recur for right subarray
            return kthSmallest(arr, index + 1, r, k - index + l - 1);
        }
    
        // If k is more than number of 
        // elements in array
        return -1;
    }

    myType WCSelect(int k) {
        return -1;
    }

    void stableSort() {
        mergeSort(array, 0, sizeNum - 1);
        front = 0;
        back = length() - 1;
    }

    int linearSearch(myType e) {
        for(int i = 0; i < capacityNum; i++) {
            if(array[i] == e) {
                return i;
            }
        }

        return -1;
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
};