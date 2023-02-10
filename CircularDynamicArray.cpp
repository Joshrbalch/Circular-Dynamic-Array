// This program was made by Joshua Balch at the University of Alabama

#include <iostream>
template <class myType>

class CircularDynamicArray {
    private:
    int capacityNum;
    int sizeNum;
    int front;
    int back;
    bool empty;
    myType* array;
    bool reversed;
    bool reverseFlag = 0;

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

    int partition(myType arr[], int l, int r, int pivotIndex) {
        myType pivotValue = array[pivotIndex];

        std::swap(array[pivotIndex], array[r]);

        int storeIndex = l;

        for(int i = l; i <= r; i++) {
            if(array[i] < pivotValue) {
                std::swap(array[i], array[storeIndex]);
                storeIndex++;
            }
        }

        std::swap(array[storeIndex], array[r]);
        return storeIndex;
    }

    void mergeSort(myType array[], int l, int r) {
        if(l < r) {
            int m = (l + r) / 2;
            mergeSort(array, l, m);
            mergeSort(array, m + 1, r);
            merge(array, l, m, r);
        }
    }

    void merge(myType array[], int const left, int const mid, int const right) {

        myType const subArrayOne = mid - left + 1;
        myType const subArrayTwo = right - mid;
    
        // Create temp arrays
        myType *leftArray = new myType[subArrayOne], *rightArray = new myType[subArrayTwo];
    
        // Copy data to temp arrays leftArray[] and rightArray[]
        for (int i = 0; i < subArrayOne; i++) {
            leftArray[i] = array[(left + i) % capacityNum];
        }

        for (int j = 0; j < subArrayTwo; j++) {
            rightArray[j] = array[(mid + 1 + j) % capacityNum];
        }
    
        int indexOfSubArrayOne = 0, // Initial index of first sub-array
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
    reversed = false;
    array = new myType[capacityNum];
    }

    CircularDynamicArray(int s) {
        capacityNum = s;
        sizeNum = s;
        front = 0;
        back = 1;
        empty = 1;
        reversed = false;
        array = new myType[capacityNum];
    }

    ~CircularDynamicArray() {
        delete [] array;
        array = nullptr;
    }

    CircularDynamicArray(const CircularDynamicArray& other) {
        capacityNum = other.capacityNum;
        sizeNum = other.sizeNum;
        front = other.front;
        back = other.back;
        empty = other.empty;
        reversed = other.reversed;

        array = new myType[sizeNum];
        int j = front;

        for(int i = 0; i < sizeNum; i++) {
            array[j] = other.array[j];
            j = (j + 1) % capacityNum;
        }
    }

    CircularDynamicArray& operator=(const CircularDynamicArray& other) {
        if(this != &other) {
            delete[] array;
            capacityNum = other.capacityNum;
            sizeNum = other.sizeNum;
            front = other.front;
            back = other.back;
            empty = other.empty;
            reversed = other.reversed;

            array = new myType[capacityNum];
            int j = front;
            for(int i = front; i < sizeNum; i++) {
                array[j] = other.array[j];
                j = (j + 1) % capacityNum;
            }

            return *this;
        }

        return *this;
    }

    myType& operator[](int i) {
        int index = i;
        empty = 0;

        if(reversed) {
            index = (back - index + capacityNum) % capacityNum;
        }

        else {
            index = (front + index) % capacityNum;
        }

        if(index == back + 1) {
            ++back %= capacityNum;

            if(sizeNum < capacityNum) {
                sizeNum++;
            }

            // else {
            //     front = (front + 1) % capacityNum;
            // }
        }

        return array[index];
        // if(empty == true) {
        //     empty = false;
        // }

        // if(i > back) {
        //     back = i;
        // }

        // if(reversed == 0) {
        //     index = (front + i + capacityNum) % capacityNum;
        // }

        // else {
        //     index = (back - i + capacityNum) % capacityNum;
        // }

        // return array[index];
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

        if(reversed == 1 && reverseFlag == 0) {
            reverseFlag = 1;
            addFront(v);
            return;
        }

        back = (back + 1) % capacityNum;
        array[back] = v;
        sizeNum++;
        reverseFlag = 0;
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

        if(reversed == 1 && reverseFlag == 0) {
            reverseFlag = 1;
            addEnd(v);
            return;
        }

        front = (front - 1 + capacityNum) % capacityNum;
        array[front] = v;
        sizeNum++;
        reverseFlag = 0;
    }

    void delEnd() {
        if(front == back) {
            empty = true;
            sizeNum--;
            return;
        }

        if(reversed == 1 && reverseFlag == 0) {
            reverseFlag = 1;
            delFront();
            return;
        }

        back = (back - 1 + capacityNum) % capacityNum;
        sizeNum--;

        if(sizeNum <= (capacityNum / 4)) {
            decreaseSize();
        }

        reverseFlag = 0;
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

        if(reversed == 1 && reverseFlag == 0) {
            reverseFlag = 1;
            delEnd();
            return;
        }


        front++;

        if(front == capacityNum) {
            front = 0;
        }

        sizeNum--;

        if(sizeNum <= (capacityNum / 4)) {
            decreaseSize();
        }

        reverseFlag = 0;
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
        int n = sizeNum;
        return kthSmallest(array, 0, n - 1, (k - 1 + n) % n);
    }

    myType kthSmallest(myType arr[], int l, int r, int k) {
        if(l == r) {
            return array[l];
        }

        int pivotIndex = l + (rand() % (r - l + 1));
        pivotIndex = partition(array, l, r, pivotIndex);

        if(k == pivotIndex) {
            return array[k];
        }

        else if(k < pivotIndex) {
            return kthSmallest(array, l, pivotIndex - 1, k);
        }

        else {
            return kthSmallest(array, pivotIndex + 1, r, k);
        }
    }

    void stableSort() {
        int n = sizeNum;
        mergeSort(array, 0, n - 1);
        front = 0;
        back = length() - 1;
    }

    int linearSearch(myType e) {
        int j = front;
        for(int i = 0; i < capacityNum; i++) {
            
            if(array[j] == e) {
                return i;
            }

            j = (j + 1) % capacityNum;
        }

        return -1;
    }

    int binSearch(myType e) {
        return binSearchRec(array, 0, capacityNum - 1, e);
    }

    int binSearchRec(myType array[], int l, int r, int e) {
        if(r >= l) {
            int mid = l + (r - l) / 2;

            if(array[mid] == e) {
                return mid;
            }

            if(array[mid] > e) {
                return binSearchRec(array, l, mid - 1, e);
            }

            else {
                return binSearchRec(array, mid + 1, r, e);
            }
        }

        return -1;
    }

    void reverse() {
        reversed = !reversed;
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
        if(reversed == 0) {
            int j = front;
            for(int i = 0; i < sizeNum; i++) {
                if(j == capacityNum) {
                    j = 0;
                }

                std::cout << array[j] << " ";

                j++;
            }
        }

        else {
            int j = back;
            for(int i = 0; i < sizeNum; i++) {
                if(j == 0) {
                    j = capacityNum - 1;
                }

                std::cout << array[j] << " ";

                j--;
            }
        }

        std::cout << std::endl;
    }

    int getBack() {
        return back;
    }
};