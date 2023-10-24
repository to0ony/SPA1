#include <iostream>
using namespace std;

// Spajanje dva polja u sortirano polje
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Velicina lijevog polja
    int n2 = right - mid;    // Velicina desnog polja

    //temporary arrays
    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    //filling temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = left;

    // merging sortedd subbarays
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements from the left and right subarrays
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    // Cleaning memory
    delete[] leftArr;
    delete[] rightArr;
}

// Merge sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Calculate the middle index

        // Recursively sort the left and right halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[] = { 16, 6, 27, 7, 31, 17, 333 };
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "Before MergeSort: ";
    printArray(arr, arrSize);

    mergeSort(arr, 0, arrSize - 1);

    cout << "Sorted array: ";
    printArray(arr, arrSize);

    return 0;
}

