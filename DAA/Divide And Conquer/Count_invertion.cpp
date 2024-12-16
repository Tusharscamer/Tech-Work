#include <iostream>
using namespace std;
int mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;    // Left subarray index
    int j = mid + 1; // Right subarray index
    int k = left;    // Temporary array index
    int invCount = 0;

    // Merge the two subarrays
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid + 1 - i); // Count inversions
        }
    }

    // Copy the remaining elements of the left subarray
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy the remaining elements of the right subarray
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back the merged elements to the original array
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}
int mergeSortAndCount(int arr[], int temp[], int left, int right) {
    int invCount = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        invCount += mergeSortAndCount(arr, temp, left, mid);
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);
        invCount += mergeAndCount(arr, temp, left, mid, right);
    }

    return invCount;
}

int main() {
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];
    cout << "Number of inversions: " << mergeSortAndCount(arr, temp, 0, n - 1) << endl;
    return 0;
}
