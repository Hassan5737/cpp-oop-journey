#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/*
     Arrays Review
    Covers:
    - Traversal
    - Searching
    - Sorting (manual + STL)
    - Min / Max
    - Passing arrays to functions
    - 2D arrays
    - Char arrays (C-style strings)
*/

// ==========================
// Print Array
// ==========================
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ==========================
// Linear Search
// ==========================
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// ==========================
// Find Min & Max
// ==========================
int getMin(int arr[], int size) {
    int mn = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < mn)
            mn = arr[i];
    }
    return mn;
}

int getMax(int arr[], int size) {
    int mx = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > mx)
            mx = arr[i];
    }
    return mx;
}

// ==========================
// Reverse Array
// ==========================
void reverseArray(int arr[], int size) {
    int left = 0, right = size - 1;

    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

// ==========================
// Bubble Sort (Manual)
// ==========================
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// ==========================
// Binary Search (Array must be sorted)
// ==========================
int binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

// ==========================
// 2D Array Print
// ==========================
void printMatrix(int matrix[][3], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// ==========================
// Char Array Demo
// ==========================
void charArrayDemo() {
    char str1[10] = "Hello";
    char str2[10] = "World";

    cout << "Length of str1: " << strlen(str1) << endl;
    cout << "Compare str1 & str2: " << strcmp(str1, str2) << endl;
}

// ==========================
// MAIN
// ==========================
int main() {

    cout << "=== Arrays Review ===" << endl;

    int arr[] = {22, 55, 88, 99, 1, 0, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, size);

    // Search
    int index = linearSearch(arr, size, 55);
    cout << "Linear Search (55): " << index << endl;

    // Min / Max
    cout << "Min: " << getMin(arr, size) << endl;
    cout << "Max: " << getMax(arr, size) << endl;

    // Reverse
    reverseArray(arr, size);
    cout << "Reversed: ";
    printArray(arr, size);

    // Sort
    bubbleSort(arr, size);
    cout << "Sorted (Bubble): ";
    printArray(arr, size);

    // STL Sort
    sort(arr, arr + size);
    cout << "Sorted (STL): ";
    printArray(arr, size);

    // Binary Search
    int idx = binarySearch(arr, size, 55);
    cout << "Binary Search (55): " << idx << endl;

    // 2D Array
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Matrix:" << endl;
    printMatrix(matrix, 3);

    // Char Array
    charArrayDemo();

    return 0;
}