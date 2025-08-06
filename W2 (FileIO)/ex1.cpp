#include <iostream>

int getMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        min = (arr[i] < min) ? arr[i] : min;
    }
    return min;
}

int main() {
    int arr[] = {5,3,2,9,4,1,4};
    std::cout << "The minimum element of the array: " << getMin(arr, sizeof(arr) / sizeof(arr[0])) << "\n";
    return 0;
}