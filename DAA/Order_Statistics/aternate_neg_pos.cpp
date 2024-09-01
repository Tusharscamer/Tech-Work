#include <iostream>
#include <algorithm>

// Function to partition the array into negative and positive numbers
int partition(int arr[], int n) {
    int i = -1;
    for (int j = 0; j < n; j++) {
        if (arr[j] < 0) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    return i + 1; // Return the index of the first positive element
}

// Function to rearrange positive and negative numbers alternatively
void rearrangeAlternately(int arr[], int n) {
    int posStart = partition(arr, n); // Partition the array

    int negIndex = 0;
    int posIndex = posStart;

    // Interleave negative and positive numbers
    while (negIndex < posIndex && posIndex < n && arr[negIndex] < 0) {
        std::swap(arr[negIndex], arr[posIndex]);
        posIndex++;
        negIndex += 2;
    }
}

int main() {
    int arr[] = {3, -2, 5, -1, 7, -4, 9, -6, 2, -8,6,10,12,14,-16,18,20,22,-24,26,-28,30,32,34,36,-38,40,42,44,46,48,-50,52,54,56,58,-60,62,64,66,68,-70,72,74,76,-78,80,82,84,-86,88,90,92,94,96,-98,-100};
    int n = sizeof(arr) / sizeof(arr[0]);

    rearrangeAlternately(arr, n);

    std::cout << "Rearranged array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
