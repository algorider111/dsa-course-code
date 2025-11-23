#include <bits/stdc++.h>
using namespace std;

class DynamicArray {
private:
    int *arr;          // pointer to raw array
    int capacity;      // total allocated memory
    int currentSize;   // number of elements stored

    /*
        expand()
        Doubles the capacity when the array becomes full.
        Time Complexity: O(N) due to copying all elements.
    */
    void expand() {
        int newCapacity = capacity * 2;
        int *newArr = new int[newCapacity];

        for (int i = 0; i < currentSize; i++) {
            newArr[i] = arr[i];   // copy old array to new
        }

        delete[] arr;             // release old memory
        arr = newArr;
        capacity = newCapacity;
    }

public:
    /*
        Constructor
        Creates an array with initial capacity.
        Time Complexity: O(1)
    */
    DynamicArray(int initialCapacity = 2) {
        arr = new int[initialCapacity];
        capacity = initialCapacity;
        currentSize = 0;
    }

    /*
        size()
        Returns number of elements stored.
        Time Complexity: O(1)
    */
    int size() const {
        return currentSize;
    }

    /*
        read(pos)
        Returns element at the given index.
        Time Complexity: O(1)
    */
    int read(int pos) const {
        if (pos < 0 || pos >= currentSize)
            throw out_of_range("Index out of range");
        return arr[pos];
    }

    /*
        update(value, pos)
        Updates element at a given position.
        Time Complexity: O(1)
    */
    void update(int value, int pos) {
        if (pos < 0 || pos >= currentSize)
            throw out_of_range("Index out of range");
        arr[pos] = value;
    }

    /*
        insert(value)
        Appends element at the end.
        Amortized Time Complexity: O(1)
        Worst-case: O(N) (when expand() is called)
    */
    void insert(int value) {
        if (currentSize == capacity) expand();
        arr[currentSize++] = value;
    }

    /*
        insert(value, pos)
        Inserts element at a specified index.
        Requires shifting elements to the right.
        Time Complexity: O(N)
    */
    void insert(int value, int pos) {
        if (pos < 0 || pos > currentSize)
            throw out_of_range("Index out of range");

        if (currentSize == capacity) expand();

        for (int i = currentSize; i > pos; i--) {
            arr[i] = arr[i - 1];  // shift right
        }

        arr[pos] = value;
        currentSize++;
    }

    /*
        remove(pos)
        Removes element at a given index.
        Requires shifting elements to the left.
        Time Complexity: O(N)
    */
    void remove(int pos) {
        if (pos < 0 || pos >= currentSize)
            throw out_of_range("Index out of range");

        for (int i = pos; i < currentSize - 1; i++) {
            arr[i] = arr[i + 1];  // shift left
        }

        currentSize--;
    }

    /*
        print()
        Prints all elements.
        Time Complexity: O(N)
    */
    void print() const {
        for (int i = 0; i < currentSize; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    /*
        Destructor
        Frees allocated memory.
        Time Complexity: O(1)
    */
    ~DynamicArray() {
        delete[] arr;
    }
};

int main() {
    DynamicArray a;

    a.insert(10);
    a.insert(20);
    a.insert(30);
    a.insert(40);

    a.insert(15, 1);   // insert at index 1
    a.remove(2);       // remove element at index 2

    a.print();         // output: 10 15 30 40

    return 0;
}
