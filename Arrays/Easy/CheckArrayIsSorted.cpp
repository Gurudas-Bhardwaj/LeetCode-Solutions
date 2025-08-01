#include <iostream>
using namespace std;

bool check(int arr[], int size) {
    int count = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i - 1] > arr[i])
            count++;
    }

    if (arr[0] < arr[size - 1])
        count++;

    return count <= 1 ? 1 : 0;
}

int main() {
    int arr1[] = {3, 4, 5, 1, 2};  // rotated sorted array
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    
    int arr2[] = {1, 2, 3, 4, 5};  // sorted array
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int arr3[] = {2, 1, 3, 4, 5};  // not rotated sorted array
    
    cout << "Check arr1: " << (check(arr1, size1) ? "True" : "False") << endl;
    cout << "Check arr2: " << (check(arr2, size2) ? "True" : "False") << endl;
    cout << "Check arr3: " << (check(arr3, sizeof(arr3)/sizeof(arr3[0])) ? "True" : "False") << endl;

    return 0;
}
